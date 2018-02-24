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
	getchar();
	getchar();
	return 0;
}

void Josephus(CircList &list, int num, int gap)
{
	Node *prev = list.getHead(), *ptr;
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < gap - 1; j++)
			prev = prev->next;
		ptr = prev->next;

		cout << ptr->val << " is out." << endl;
		
		if (ptr == list.getHead())
			list.setHead();
		else
		{
			prev->next = ptr->next;
			free(ptr);
		}
		list.display();
		cout << endl;
	}
}