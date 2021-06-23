#include <iostream>
#include <ctime>
#include "CArray.h"
using namespace std;

int main()
{
	srand(time(NULL));

	CArray<int> p;
	p[0] = rand() % 100;
	for (int i = 1; i < 20; i++)
	{
		p.push_back(rand() % 100);
	}

	p.print();

	cout << "sort" << endl;
	p.sort();

	p.print();

	cout << "erase" << endl;
	int k = p.size() / 2;
	for (int i = 1; i <= k; i = i++)
	{
		p.erase(i);
	}
	p.print();

	cout << "rand" << endl;
	for (int i = 0; i < 10; i++)
	{
		p[rand() % 9] = rand() % 100;
	}

	p.print();

	p.clear();
	p.print();
};