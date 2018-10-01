// Assignemt1_Q2c.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <thread>
#include <time.h>
#include <ctime>
using namespace std;

void add() {
#pragma warning(disable:4996)
	int a[1024][1024];
	int b[1024][1024];
	int sum[1024][1024];


	for (int j = 0; j < 1024; ++j)
	{
		for (int i = 0; i < 1024; ++i)
		{
			//multiplying for random values
			a[j][i] = j*i;
			b[j][i] = j*i;
		}
	}


	for (int i = 0; i < 1024; ++i)
	for (int j = 0; j < 1024; ++j)
		sum[i][j] = a[i][j] + b[i][j];

	// Displaying the resultant matrix.
	cout << endl << "Performing addition: " << endl;

}

void sub() {
	int a[1024][1024];
	int b[1024][1024];
	int sum[1024][1024];


	for (int j = 0; j < 1024; ++j)
	{
		for (int i = 0; i < 1024; ++i)
		{
			//multiplying for random values
			a[j][i] = j*i;
			b[j][i] = j*i;
		}
	}

	for (int i = 0; i < 1024; ++i)
	for (int j = 0; j < 1024; ++j)
		sum[i][j] = a[i][j] - b[i][j];

	// Displaying the resultant matrix.
	cout << endl << "Now Performing subtraction: " << endl;


}

void mulf()
{
#pragma warning(disable:4996)
	int a[1024][1024];
	int b[1024][1024];

	int mult[1024][1024];

	for (int j = 0; j < 1024; ++j)
	{
		for (int i = 0; i < 1024; ++i)
		{
			//multiplying for random values
			a[j][i] = j*i;
			b[j][i] = j*i;
		}
	}

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
	cout << endl << "Output Matrix: " << endl;


}
int main()
{

#pragma warning(disable:4996)
	thread t1(add);
	thread t2(sub);
	thread t3(mulf);


	time_t mul_time_start = time(NULL);

	t1.join();
	t2.join();
	t3.join();


	time_t mul_time_end = time(NULL);
	printf("%s", ctime(&mul_time_start));
	printf("%s", ctime(&mul_time_end));

	return 0;
}



