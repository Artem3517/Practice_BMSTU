#include "field.h"
#include <iostream>
#include <stdio.h>
using namespace std;

Field::Field() {
	int N, i, j;
	i = j = N = 0;
	while (N % 2 != 1 || N < 3) {
		cout << "Enter the size of the matrix: ";
		cin >> N;
	}
	this->N = N;
	this->M = new int*[N];
	for (i = 0; i < N; i++) {
		this->M[i] = new int[N];
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			this->M[i][j] = 0;
		}
	}
	cout << "Game started!" << endl;
	this->M[N/2][N/2] = 1;
}

void Field::draw() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%-4d", M[i][j]);
		}
		putchar('\n');
	}
}

int Field::getval(int x, int y, int k) {
	if (x < 0 || x > N - 1 || y < 0 || y > N - 1 || M[x][y] != 0)
		return -1;
	if (x == 0 && y == 0) {							// top left corner
		if (M[x+1][y] % 2 == k && M[x+1][y] != 0 || M[x][y+1] % 2 == k && M[x][y+1] != 0)
			return -1;
	}
	if (x == 0 && y == N - 1) {						// top right corner
		if (M[x+1][y] % 2 == k && M[x+1][y] != 0 || M[x][y-1] % 2 == k && M[x][y-1] != 0)
			return -1;
	}
	if (x == N - 1 && y == N - 1) {					// bottom right corner
		if (M[x-1][y] % 2 == k && M[x-1][y] != 0 || M[x][y-1] % 2 == k && M[x][y-1] != 0)
			return -1;
	}	
	if (x == N - 1 && y == 0) {						// bottom left corner
		if (M[x-1][y] % 2 == k && M[x-1][y] != 0 || M[x][y+1] % 2 == k && M[x][y+1] != 0)
			return -1;
	}
	if (x == 0 && y > 0 && y < N - 1) {				// top row
		if (M[x+1][y] % 2 == k && M[x+1][y] != 0 || M[x][y+1] % 2 == k && M[x][y+1] != 0 || M[x][y-1] % 2 == k && M[x][y-1] != 0)
			return -1;
	}
	if (x > 0 && x < N - 1 && y == N - 1) {			// right column
		if (M[x+1][y] % 2 == k && M[x+1][y] != 0 || M[x-1][y] % 2 == k && M[x-1][y] != 0 || M[x][y-1] % 2 == k && M[x][y-1] != 0)
			return -1;
	}
	if (x == N - 1 && y > 0 && y < N - 1) {			// bottom row
		if (M[x][y+1] % 2 == k && M[x][y+1] != 0 || M[x][y-1] % 2 == k && M[x][y-1] != 0 || M[x-1][y] % 2 == k && M[x-1][y] != 0)
			return -1;
	}
	if (x > 0 && x < N - 1 && y == 0) {				// left column
		if (M[x+1][y] % 2 == k && M[x+1][y] != 0 || M[x-1][y] % 2 == k && M[x-1][y] != 0 || M[x][y+1] % 2 == k && M[x][y+1] != 0)
			return -1;
	}
	if (x > 0 && x < N - 1 && y > 0 && y < N - 1) { // other situations
		if (M[x+1][y] % 2 == k && M[x+1][y] != 0 || M[x-1][y] % 2 == k && M[x-1][y] != 0 || M[x][y+1] % 2 == k && M[x][y+1] != 0 || M[x][y-1] % 2 == k && M[x][y-1] != 0)
			return -1;
	}
	return 0;
}

void Field::setval(int x, int y, int num) {
		M[x][y] = num;
}

Field::~Field() {
	for (int i = 0; i < N; i++) {
		delete[] M[i];
	}
	delete[] M;
}
