#include "pch.h"
#include <iostream>
#include <math.h>
#include "stdio.h"
using namespace std;

const int sizeOfLine = 5;

void readArr(float Array[sizeOfLine][sizeOfLine])
{
	int row, column;

	for (row = 0; row < sizeOfLine; row++)
	{
		for (column = 0; column < sizeOfLine; column++)
		{
			cin >> Array[row][column];
		}
		cout << endl;
	}
	cout << endl;
}


void printArr(float Array[sizeOfLine][sizeOfLine])
{
	for (int i = 0; i < sizeOfLine; i++) {
		for (int j = 0; j < sizeOfLine; j++) {
			cout << "\t" << Array[i][j];
		}
		cout << endl;
	}
}

void swapForBubbleSort(float *num1, float *num2) {

	float buffer;

	if (*num1 > *num2) {
		buffer = *num1;
		*num1 = *num2;
		*num2 = buffer;
	}
}

//sort columns in descending way 
void bubbleSort(float Array[sizeOfLine][sizeOfLine]){

	int column, row, additionalVar;

	for (column = 0; column < sizeOfLine; column++) {
		for (row = 1; row < sizeOfLine; row++){

			for (additionalVar = (sizeOfLine - 1); additionalVar > (row - 1); additionalVar--){
				swapForBubbleSort(&Array[additionalVar][column], &Array[additionalVar - 1][column]);
			}

		}	
	}
}

/*
	f - average geometrical in a row above the main diagonal
	F - sum of f-variables
*/
void findFf(float Array[sizeOfLine][sizeOfLine]) {

	float F = 0.0;
	float tempVar, f;

	for (int row = 0; row < sizeOfLine; row++) {

		tempVar = 1.0;

		for (int column = (sizeOfLine - 1); column > row; column--) {
			tempVar *= Array[row][column];
		}

		if (row < 4) {
			f = pow(tempVar, (1.0 / ((sizeOfLine - 1) - row)));
			cout << "f = " << f << endl;
			F += f;
		}
	}

	cout << endl;
	cout << "F = " << F << "\n";
}


int main()
{
	float Array[sizeOfLine][sizeOfLine];

	readArr(Array);
	printArr(Array);
	cout << endl;

	bubbleSort(Array);
	printArr(Array);
	cout << endl;

	findFf(Array);
}