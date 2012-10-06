#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

struct result
{
	string sentence;
	result *next;
};

void buildList(int n, result *&head)
{
	result *p, *q;
	char s[32];
	p = head = new result;
	p->sentence = *(new string(itoa(n, s, 4)));
	while(n > 0)
	{
		n--;
		q = new result;
		q->sentence = *(new string(itoa(n, s, 4)));
		q->next = NULL;
		p->next = q;
		p = p->next;
	}
}

void showList(result *head)
{
	result *p = head;
	while(p)
	{
		cout<<p->sentence<<ends;
		p = p->next;
	}
	cout<<endl;
}

void insertSort(result *&head)
{
	result *preHead = new result, *p, *q, *temp;
	bool unchanged;
	preHead->next = head;
	p = preHead->next;
	while(p->next)
	{
		unchanged = true;
		q = preHead;
		while(q->next != p->next)
		{	
			if(p->next->sentence <= q->next->sentence)
			{		
				temp = p->next->next;
				p->next->next = q->next;
				q->next = p->next;
				p->next = temp;
				unchanged = false;
				break;
			}
			q = q->next;
		}
		if(unchanged)
			p = p->next;
	}
	head = preHead->next;
}

void main()
{
	result *head;
	buildList(24, head);
	showList(head);
	insertSort(head);
	showList(head);
}

