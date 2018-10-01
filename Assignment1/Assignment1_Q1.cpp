// ConsoleApplication11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
 Q1
#include <iostream>


using namespace std;
int foo2[20];

void check(int index) {
	for (size_t i = 0; i < 20; i++)
	{
		if (foo2[i] == 0)
		{
			foo2[i] = index;
			break;
		}
		else if (foo2[i] == index)
		{
			break;
		}
	}
}

int main()
{
	for (int a = 0; a < 20; a = a + 1) {
		int i;

		cout << a << " >> Please enter an integer value: ";
		cout << "\n\r";
		cin >> i;

		if (i >= 10 && i <= 100)
		{
			check(i);
		}
		else
		{
			cout << "Incorrect range: ";
			cout << "\n\r";
			a = a - 1;

		}
	}

	for (size_t i = 0; i < 20; i++)
	{
		cout << foo2[i] << ", ";
	}
	return 0;
}



