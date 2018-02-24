#ifndef CIRCLIST_H
#define CIRCLIST_H
#include <cstdlib>
#include <iostream>
using namespace std;

struct Node
{
	int val;
	Node *next;
};
class CircList
{
	Node *head, *last;//循环链表需要一个尾节点标志
public:
	CircList() { head = last = NULL; }//默认构造函数
	~CircList();
	int length()const;
	Node *getHead()const { return head; }//返回头节点的内存地址
	void setHead();//移除头节点，将下一节点变为头节点
	Node *getAddr(int pos)const;//返回当前节点的内存地址
	int getData(int pos)const;//返回当前位置的数据
	void setData(int pos, int &val);//修改当前位置的数据
	bool insert(int pos, int &val);//在当前位置插入数据
	bool add(int &val);//队尾添加新节点
	bool remove(int pos);//删除当前位置节点
	void display();
};

inline CircList::~CircList()
{
	Node *ptr;
	last->next = NULL;
	while (head->next != NULL)
	{
		ptr = head->next;
		free(head);
		head = ptr;
	}
	free(head);
	head = last = NULL;
}

inline int CircList::length() const
{
	if (head == NULL)
		return 0;

	int count = 0;
	Node *ptr = head;

	while (ptr != last)
	{
		ptr = ptr->next;
		count++;
	}
	return count + 1;
}

inline void CircList::setHead()
{
	Node *p = head;
	head = head->next;
	last->next = head;
	free(p);
}

inline Node * CircList::getAddr(int pos) const
{
	if (pos < 0)
		throw "Invalid position!";
	else if (pos >= length())
		throw "Out of range!";

	Node *ptr = head;
	for (int i = 0; i < pos; i++)
		ptr = ptr->next;
	return ptr;
}

inline int CircList::getData(int pos) const
{
	if (pos < 0)
		throw "Invalid position!";
	else if (pos >= length())
		throw "Out of range!";

	Node *ptr = head;
	for (int i = 0; i < pos; i++)
		ptr = ptr->next;
	return ptr->val;
}

inline void CircList::setData(int pos, int & val)
{
	if (pos < 0)
		throw "Invalid position!";
	else if (pos >= length())
		throw "Out of range!";

	Node *ptr = head;
	for (int i = 0; i < pos; i++)
		ptr = ptr->next;
	ptr->val = val;
}

inline bool CircList::insert(int pos, int & val)
{
	if (pos < 0)
		throw "Invalid position!";
	else if (pos >= length())
		throw "Out of range!";
	else if (pos == length())
		return add(val);//结尾添加

	Node *ptr, *prev = head;
	Node *p = (struct Node*)malloc(sizeof(Node));
	if (p == NULL)
		throw "No enough memory! Allocation failed.";

	for (int i = 0; i < pos; i++)
		prev = prev->next;
	ptr = prev->next;

	prev->next = p;
	p->val = val;
	p->next = ptr;
	return true;
}

inline bool CircList::add(int & val)
{
	Node *p = (struct Node*)malloc(sizeof(Node));
	if (p == NULL)
		throw "No enough memory! Allocation failed.";

	if (head == NULL)
	{
		p->val = val;
		p->next = head;
		head = last = p;
		head->next = last->next = head;
	}
	else
	{
		last->next = p;
		last = p;
		last->val = val;
		last->next = head;
	}
	return true;
}

inline bool CircList::remove(int pos)
{
	if (pos < 0)
		throw "Invalid position!";
	else if (pos >= length())
		throw "Out of range!";

	if (pos == 0)
	{
		Node *p = head;
		head = head->next;
		last->next = head;
		free(p);
	}
	else
	{
		Node *prev = head, *ptr;
		for (int i = 0; i < pos - 1; i++)
			prev = prev->next;
		ptr = prev->next;
		prev->next = ptr->next;
		free(ptr);
	}
	return true;
}

inline void CircList::display()
{
	Node *p = head;
	if (head == NULL)
		return;
	else if (head == last)
		cout << head->val;
	else
	{
		while (p != last)
		{
			cout << p->val << ' ';
			p = p->next;
		}
		cout << last->val;
	}
}
#endif // !CIRCLIST_H