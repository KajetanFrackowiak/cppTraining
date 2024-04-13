#ifndef ARRAYS_H
#define ARRAYS_H

#include <iostream>

int** create2DArray(int rows, int columns);

void delete2DArray(int** array, int rows);

int*** delete3DArray(int depth, int rows, int column);

int delete2DArray(int*** array, int depth, int rows);

#endif // ARRAYS_H