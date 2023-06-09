#include<iostream>
#include<fstream>

using namespace std;

int blockSize = 10;
double reqInterval = 23; 
double workInterval[2] = { 22, 14 };
double simulationTime = 3600;

double getRandomUniform(double maxInterval) {
	return maxInterval * rand() / RAND_MAX;
}

struct Queue {
	int len;
	int capacity; 
	int* reqArray; 
};

Queue* setQueue() {
	Queue* q = new Queue;
	q->len = 0;
	q->capacity = 0;
	q->reqArray = nullptr;
	return q;
}

void freeQueue(Queue* q)  {
	if (q->reqArray != nullptr)
		delete[] q->reqArray;
	delete q;
}

void addRequest(Queue* q, int reqNumber) {
	if (q->len == q->capacity)
	{
		q->capacity += blockSize;
		int* newArray = new int[q->capacity];
		for (int i = 0; i < q->len; i++)
			newArray[i] = q->reqArray[i];
		if (q->reqArray != nullptr)
			delete[] q->reqArray;
		q->reqArray = newArray;
	}
	q->reqArray[q->len++] = reqNumber;
}

void delRequest(Queue* q) {
	q->len--;
	for (int i = 0; i < q->len; i++)
		q->reqArray[i] = q->reqArray[i + 1];
}

int getLen(Queue* q) {
	return q->len;
}

int getFirst(Queue* q) {
	return q->reqArray[0];
}

int main() {
	srand(time(NULL));
	ofstream out("log.txt", ios::out);
	out << fixed;
	double curTime = 0.0; 
	int requestNumber = 1;
	double timeToNextRequest = getRandomUniform(reqInterval);
	bool deviceOccupation[2] = { false, false };
	double timeToFinish[2] = { 0.0, 0.0 };
	Queue* queues[2];
	queues[0] = setQueue();
	queues[1] = setQueue();
	out << "Работа модели началась" << endl;
	while (curTime <= simulationTime)
	{
		if (timeToNextRequest == 0.0)
		{
			int reqNum = requestNumber++;
			out << "B момент времени " << curTime << " транзакт " << reqNum << " вошёл в модель" << endl; // транзакт создан
			timeToNextRequest = getRandomUniform(reqInterval);
			if (queues[0]->len <= queues[1]->len) // попадает в меньшую очередь
			{
				addRequest(queues[0], reqNum);
				if (!deviceOccupation[0]) // занимает 1 устройство
				{
					out << "B момент времени " << curTime << " транзакт " << reqNum << " занял первое устройство" << endl;
					deviceOccupation[0] = true;
					timeToFinish[0] = getRandomUniform(workInterval[0]);
				}
				else // иначе попадает в 1 очередь
				{
					out << "B момент времени " << curTime << " транзакт " << reqNum << " встал в первую очередь" << endl;
				}
			}
			else
			{
				addRequest(queues[1], reqNum);
				if (!deviceOccupation[1]) // занимает 2 устройство
				{
					out << "B момент времени " << curTime << " транзакт " << reqNum << " занял второе устройство" << endl;
					deviceOccupation[1] = true;
					timeToFinish[1] = getRandomUniform(workInterval[1]);
				}
				else // иначе попадает вo 2 очередь
				{
					out << "B момент времени " << curTime << " транзакт " << reqNum << " встал во вторую очередь" << endl;
				}
			}
		}
		for (int i = 0; i < 2; i++)
		{
			if (deviceOccupation[i] && (timeToFinish[i] == 0.0)) // обработка завершена
			{
				out << "B момент времени " << curTime << " транзакт " << getFirst(queues[i]) << " освободил устройство " << (i + 1) << endl;
				out << "B момент времени " << curTime << " транзакт " << getFirst(queues[i]) << " вышел из модели" << endl;
				delRequest(queues[i]);
				if (getLen(queues[i]) > 0)
				{
					timeToFinish[i] = getRandomUniform(workInterval[i]);
					out << "B момент времени " << curTime << " транзакт " << getFirst(queues[i]) << " занял устройство " << (i + 1) << endl;
				}
				else
				{
					deviceOccupation[i] = false;
				}
			}
		}
		double minTime = timeToNextRequest;
		for (int i = 0; i < 2; i++)
			if (deviceOccupation[i] && (minTime > timeToFinish[i]))
				minTime = timeToFinish[i];
		timeToNextRequest -= minTime;
		for (int i = 0; i < 2; i++)
		{
			if (deviceOccupation[i])
				timeToFinish[i] -= minTime;
		}
		curTime += minTime;
	}
	out << "Работа модели завершена. Время симуляции, равное 3600 секнуд закончено." << endl;
	freeQueue(queues[0]);
	freeQueue(queues[1]);
	out.close();
	return 0;
}
