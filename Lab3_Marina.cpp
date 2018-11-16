
#include "pch.h"
#include <iostream>
#include <math.h>
#include "stdio.h"
using namespace std;


int CreateArr(float arr[5][5])
{
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			cin >> arr[i][j];
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}


int PrintArr(float arr [5][5])
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << "\t" << arr[i][j];
		}
		cout << endl;
	}
	return 0;
}


void Bubble(float arr[5][5])
{
	int i, j, k;
	float s;
	for (j = 0; j < 5; j++) {
		for (i = 1; i < 5; i++){
			for (k = 4; k > (i - 1); k--){
				if (arr[k][j] > arr[k - 1][j]) {
					s = arr[k][j];
					arr[k][j] = arr[k - 1][j];
					arr[k - 1][j] = s;
				}
			}
		}	
	}
}


int main()
{
	float a[5][5];
	float F = 0.0;
	float z, f;

	CreateArr(a);
	PrintArr(a);
	cout << endl;

	Bubble(a);
	PrintArr(a);
	cout << endl;

	for (int i = 0; i <  5; i++){
		z = 1.0;
		for (int j = 4; j > i; j--) {
			z = z * a[i][j];
		}
		if (i < 4) {
			f = pow(z, (1.0 / (4.0 - i)));
			cout << "f = " << f << endl;
			F += f;
		}
	}
	cout << endl;
	cout << "F = " << F << "\n";
}