#include <iostream>
//#include"stdafx.h"
using namespace std;
template <class T>
class LinkNode
{
public:
	T data;
	LinkNode<T> *pred, *succ;
	LinkNode(const T &el, LinkNode<T> *ptrl = 0, LinkNode<T> *ptrr = 0)
	{
		data = el;
		pred = ptrl;
		succ = ptrr;
	}
};
template <class T>
class LinkList
{
public:
	LinkNode<T> *head, *tail;
	LinkNode<T> *prevptr, *currptr;
	int pos;
	LinkList()
	{
		head = new LinkNode<T>(0);
		tail = head;
	}
	~LinkList()
	{
		delete head, tail, prevptr, currptr;
	}
	void insert(T data)
	{
		LinkNode<T> *temp = new LinkNode<T>(data, temp);
		tail->succ = temp;
		tail = tail->succ;
		return;
	}
	void show()
	{
		LinkNode<T> *t = head->succ;
		while (t != 0)
		{
			cout << t->data << "\t";
			t = t->succ;
		}
		cout << endl;
		cout << "-------" << endl;
	}
};
int main()
{
	LinkList<int> list;
	list.insert(1);
	list.insert(2);
	list.insert(3);
	list.insert(4);
	list.insert(5);
	list.insert(6);
	list.insert(7);
	list.insert(8);
	list.show();
	LinkNode<int> *l, *r, *k, *s, *t;
	int i = 1;
	l = new LinkNode<int>(0);
	r = new LinkNode<int>(0);
	LinkList<int> head;
	k = list.head->succ;
	s = list.head->succ;
	t = list.head->succ->succ;
	while (k != 0)
	{
		if (i % 2 == 1)
		{
			l->succ = k;
			k->pred = l;
			l = l->succ;
			k = k->succ;
			i++;
		}
		else
		{
			r->pred = k;
			k = k->succ;
			r->pred->succ = r;
			r = r->pred;
			i++;
		}
	}
	l->succ = r;
	r->pred = l;
	head.head->succ = s;
	t->succ = 0;
	head.show();
	return 0;
}
