// Assignment1_Q2a.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <ctime>
using namespace std;

int a[1024][1024];
int b[1024][1024];
int sum[1024][1024];
int mult[1024][1024];

void ToPerform() {

#pragma warning(disable:4996)

	time_t mul_time_start = time(NULL);
	cout << endl << "Now Performing Addition: " << endl;
	for (int i = 0; i < 1024; ++i)
	for (int j = 0; j < 1024; ++j)
		sum[i][j] = a[i][j] + b[i][j];

	for (int i = 0; i < 1024; ++i)
	for (int j = 0; j < 1024; ++j)
		sum[i][j] = a[i][j] - b[i][j];

	// Displaying the resultant matrix.
	cout << endl << "Now Performing subtraction: " << endl;

	// Initializing elements of matrix mult to 0.
	for (int i = 0; i < 1024; ++i)
	for (int j = 0; j < 1024; ++j)
	{
		mult[i][j] = 0;
	}

	// Multiplying matrix a and b and storing in array mult.
	for (int i = 0; i < 1024; ++i)
	for (int j = 0; j < 1024; ++j)
	for (int k = 0; k < 1024; ++k)
	{
		mult[i][j] += a[i][k] * b[k][j];
	}

	// Displaying the multiplication of two matrix.
	cout << endl << "Performing multiplication: " << endl;

	time_t mul_time_end = time(NULL);
	printf("Starting time: %s", ctime(&mul_time_start));
	printf("Ending time: %s", ctime(&mul_time_end));
}

int main()
{
	//initializing matrixes
	for (int j = 0; j < 1024; ++j)
	{
		for (int i = 0; i < 1024; ++i)
		{
			//multiplying for random values
			a[j][i] = j*i;
			b[j][i] = j*i;
		}
	}
	ToPerform();
	return 0;
}


