// ConsoleApplication2.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <ctime>
#include <omp.h>

using namespace std;

int a[1200][1200];
int b[1200][1200];
int sum[1200][1200];
int mult[1200][1200];

void add() {

#pragma warning(disable:4996)

	cout << endl << "Now Performing Addition: " << endl;
	time_t add_time_start = time(NULL);

#pragma omp parallel for schedule(guided,100)
		for (int i = 0; i < 1200; ++i)
		for (int j = 0; j < 1200; ++j)
			sum[i][j] = a[i][j] + b[i][j];

	time_t add_time_end = time(NULL);
	printf("%s", ctime(&add_time_start));
	printf("%s", ctime(&add_time_end));



}

void sub() {

	cout << endl << "Now Performing subtraction: " << endl;
	time_t sub_time_start = time(NULL);

#pragma omp parallel for schedule(guided,100)
		for (int i = 0; i < 1200; ++i)
		for (int j = 0; j < 1200; ++j)
			sum[i][j] = a[i][j] - b[i][j];

		time_t sub_time_end = time(NULL);
		printf("%s", ctime(&sub_time_start));
		printf("%s", ctime(&sub_time_end));

}

void mulf()
{

	cout << endl << "Performing multiplication: " << endl;

	// Initializing elements of matrix mult to 0.


//#pragma omp for schedule(guided,100)
		for (int i = 0; i < 1200; ++i)
			//#pragma omp for schedule(guided,4)
		for (int j = 0; j < 1200; ++j)
		{
			mult[i][j] = 0;
		}


		time_t mul_time_start = time(NULL);
#pragma omp parallel
		{

		// Multiplying matrix a and b and storing in array mult.
#pragma omp for schedule(guided,100)
		for (int i = 0; i < 1200; ++i)
			//#pragma omp for schedule(guided,4)
		for (int j = 0; j < 1200; ++j)
			//#pragma omp for schedule(guided,4)
		for (int k = 0; k < 1200; ++k)
		{
			mult[i][j] += a[i][k] * b[k][j];
		}
	}

	// Displaying the multiplication of two matrix.

	/*for (int i = 0; i < 1200; ++i)
	for (int j = 0; j < 1200; ++j)
	{
	cout << " " << mult[i][j];
	if (j == 1200 - 1)
	cout << endl;

	}
	*/
	time_t mul_time_end = time(NULL);
	printf("%s", ctime(&mul_time_start));
	printf("%s", ctime(&mul_time_end));

}

int main()
{
	//initializing matrixes
	for (int j = 0; j < 1200; ++j)
	{
		for (int i = 0; i < 1200; ++i)
		{
			//multiplying for random values
			a[j][i] = j*i;
			b[j][i] = j*i;
		}
	}


	add(); // performing addition
	sub(); // performing subtraction
	mulf();//performing multiplication
	return 0;
}



