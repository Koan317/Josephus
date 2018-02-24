#include <iostream>
#include "CircList.h"
using namespace std;

void Josephus(CircList &list, int num, int gap);

int main()
{
	CircList list;
	int num, gap;
	cout << "Input the number of people and count gap." << endl;
	cin >> num >> gap;
	try {
		for (int i = 1; i <= num; i++)
			list.add(i);
	}
	catch (const char *msg)
	{
		cerr << msg << endl;
	}
	Josephus(list, num, gap);
	list.display();
	cout << " will enjoy the free trip." << endl;
	return 0;
}

void Josephus(CircList &list, int num, int gap)
{
	Node *prev = list.getHead();
	int count = 1;
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < gap - 1; j++)
			count++;
		count %= 8 - i;

		cout << count << " is out." << endl;
		try {
			list.remove(count--);
		}
		catch (const char *msg)
		{
			cerr << msg << endl;
		}
		list.display();
		cout << endl;
	}
}