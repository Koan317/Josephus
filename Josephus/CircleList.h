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
	CircleList(CircleList &L);//�������캯��
	~CircleList();
	int length()const;
	Node *getHead()const;//����ͷ�ڵ���ڴ��ַ
	Node *getAddr(int pos)const;//���ص�ǰ�ڵ���ڴ��ַ
	int *getData(int pos)const;//���ص�ǰλ�õ�����
	void setData(int pos, int &val);//�޸ĵ�ǰλ�õ�����
	bool insert(int pos, int &val);//�ڵ�ǰλ�ò�������
	bool remove(int pos);//ɾ����ǰλ�ýڵ�
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
