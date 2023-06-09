#include <iostream>
#include "field.h"
using namespace std;

class Human {
public:
	int move(int* x, int* y, Field* M, int num);	
};

int Human::move(int* x, int* y, Field* M, int num) {
	int count = 0;
	while (M->getval(*x, *y, 0) && count < M->getn() * M->getn() - num) {
		cout << "Enter position: ";
		cin >> *x >> *y;
		count++;
	}
	if (count < M->getn() * M->getn() - num) {
		M->setval(*x, *y, num + 1);
		return 1;
	} else {
		return 0;
	}
}

class Computer {
public:
	int move(int* x, int* y, Field* M, int num);
};

int Computer::move(int* x, int* y, Field* M, int num) {
	int temp = *x;
	*x = M->getn() - (temp + 1);
	temp = *y;
	*y = M->getn() - (temp + 1);
	if (M->getval(*x, *y, 1) == 0) {
		M->setval(*x, *y, num + 1);
		return 1;
	} else {
		M->setval(*x, *y, num + 1);
		return 0;
	}
}

int main(int argc, char** argv) {
	Field Matrix;
	Human Human;
	Computer Computer;
	int n = Matrix.getn();
	int turn = 1;
	int x, y;
	while (turn < n * n) {
		Matrix.draw();
		x = y = -1;
		if (Human.move(&x, &y, &Matrix, turn)) {
			turn++;
		} else {
			break;
		}
		if (Computer.move(&x, &y, &Matrix, turn)) {
			turn++;
		} else {
			break;
		}
	}
	Matrix.draw();
	cout << '\n' << "Game over!" << '\n' << "Winner: ";
	if (turn % 2 == 0) {
		cout << "You" << endl;
	} else {
		cout << "Computer" << endl;
	}
	return 0;
}
