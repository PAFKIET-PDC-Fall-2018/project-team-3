// Assignment1_Q2a.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <ctime>
using namespace std;

int a[800][800];
int b[800][800];
int sum[800][800];
int mult[800][800];

void add() {

#pragma warning(disable:4996)

	cout << endl << "Now Performing Addition: " << endl;
	for (int i = 0; i < 800; ++i)
	for (int j = 0; j < 800; ++j)
		sum[i][j] = a[i][j] + b[i][j];
}

void sub() {
	for (int i = 0; i < 800; ++i)
	for (int j = 0; j < 800; ++j)
		sum[i][j] = a[i][j] - b[i][j];

	// Displaying the resultant matrix.
	cout << endl << "Now Performing subtraction: " << endl;


}

void mulf()
{
	// Initializing elements of matrix mult to 0.
	for (int i = 0; i < 800; ++i)
	for (int j = 0; j < 800; ++j)
	{
		mult[i][j] = 0;
	}

	// Multiplying matrix a and b and storing in array mult.
	for (int i = 0; i < 800; ++i)
	for (int j = 0; j < 800; ++j)
	for (int k = 0; k < 800; ++k)
	{
		mult[i][j] += a[i][k] * b[k][j];
	}

	// Displaying the multiplication of two matrix.
	cout << endl << "Performing multiplication: " << endl;

}
int main()
{
	//initializing matrixes
	for (int j = 0; j < 800; ++j)
	{
		for (int i = 0; i < 800; ++i)
		{
			//multiplying for random values
			a[j][i] = j*i;
			b[j][i] = j*i;
		}
	}


	time_t mul_time_start = time(NULL);
	add(); // performing addition
	sub(); // performing subtraction
	mulf();//performing multiplication

	time_t mul_time_end = time(NULL);
	printf("%s", ctime(&mul_time_start));
	printf("%s", ctime(&mul_time_end));
	return 0;
}


