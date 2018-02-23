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
	for (int i = 1; i <= num; i++)
		list.add(i);
	Josephus(list, num, gap);
	list.display();
	cout << " will enjoy the free trip." << endl;
	return 0;
}

void Josephus(CircList &list, int num, int gap)
{
	Node *prev = list.getHead(),*ptr;
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < gap - 1; j++)
			prev = prev->next;
		ptr = prev->next;

		cout << ptr->val << " is out." << endl;
		prev->next = ptr->next;
		free(ptr);
	}
}