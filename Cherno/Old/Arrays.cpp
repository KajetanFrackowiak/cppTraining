#include "Arrays.h" 
#include <iostream>

int** create2DArray(int rows, int columns) {
	int** array = new int* [rows];
	for (int i = 0; i < rows; i++) {
		array[i] = new int[columns];
	}
	return array;
}

void delete2DArray(int** array, int rows) {
	for (int i = 0; i < rows; i++) {
		delete[] array[i];
	}
	delete[] array;
}

int*** create3DArray(int depth, int rows, int columns) {
	int*** array = new int** [depth];
	for (int i = 0; i < depth; i++) {
		array[i] = new int* [rows];
		for (int j = 0; j < rows; j++) {
			array[i][j] = new int[columns];
		}
	}
	return array;
}

void delete3DArray(int*** array, int depth, int rows) {
	for (int i = 0; i < depth; i++) {
		for (int j = 0; j < rows; j++) {
			delete[] array[i][j];
		}
		delete[] array[i];
	}
	delete[] array;
}

int main() {
	int** a2d = create2DArray(50, 50);
	a2d[0][0] = 0;
	a2d[0][1] = 1;
	delete2DArray(a2d, 50);

	int*** a3d = create3DArray(50, 50, 50);
	a3d[0][0][0] = 0;
	a3d[0][0][1] = 2;
	std::cout << "0,0,0: " << a3d[0][0][0] << std::endl;
	std::cout << "0,0,1: " << a3d[0][0][1] << std::endl;
	delete3DArray(a3d, 50, 50);

	return 0;
}