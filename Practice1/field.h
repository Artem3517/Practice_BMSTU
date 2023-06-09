#ifndef FIELD_H
#define FIELD_H

class Field {
	int** M;
	int N;
public:
	Field();
	void draw();
	int getn() {
			return N;
		};
	int getval(int x, int y, int k);
	void setval(int x, int y, int num);
	~Field();
};

#endif // FIELD_H
