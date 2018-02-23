#ifndef CIRCLELIST_H
#define CIRCLELIST_H
#include <cstdlib>
struct Node
{
	int val;
	Node *next;
};
class CircleList
{
	Node *head, *last;
public:
	CircleList(const int &val);
	CircleList(CircleList &L);//拷贝构造函数
	~CircleList();
	int length()const;
	Node *getHead()const;//返回头节点的内存地址
	Node *getAddr(int pos)const;//返回当前节点的内存地址
	int *getData(int pos)const;//返回当前位置的数据
	void setData(int pos, int &val);//修改当前位置的数据
	bool insert(int pos, int &val);//在当前位置插入数据
	bool remove(int pos);//删除当前位置节点
};

CircleList::CircleList(const int &val)
{
	Node *tempptr = head;
	Node *p = (struct Node*)malloc(sizeof(Node));

	if (p = NULL)
		throw "No enough memory! Allocation failed.";
	else if (head == NULL)
		head = p;
	else
	{
		while (tempptr->next != NULL)
			tempptr = tempptr->next;
		tempptr->next = p;
	}
	tempptr = p;
	tempptr->val = val;
	tempptr->next = NULL;

}
inline CircleList::CircleList(CircleList & L)
{
	Node *head = L.getHead();
}
inline CircleList::~CircleList()
{
}
inline int CircleList::length() const
{
	return 0;
}
#endif // !CIRCLELIST_H
