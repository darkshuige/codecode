#include<bits/stdc++.h>
#define ElemType int
#define OK 1
#define Status int
#define ERROR 0;
using namespace std;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;
Status ListMerge(LinkList &La,LinkList &Lb,LinkList &Lc)
{
	LinkList pa=La->next;
	LinkList pb=Lb->next;
	LinkList pc;
	Lc=pc=La;
	while(pa && pb)
	{
		if(pa->data>=pb->data)
		{
			pc->next=pa;pc=pa;pa=pa->next;	
		}
		else
		{
			pc->next=pb;pc=pb;pb=pb->next;	
		}
	}
	pc->next=pa?pa:pb;
	free(Lb);
	return OK;
}
Status ListReverse(LinkList L)
{
	LinkList p=L->next;
	LinkList s=p->next;
	p->next=NULL;
	while(s)
	{
		LinkList j=s->next;
		s->next=p;
		p=s;
		s=j;
		if(!s) break;
		j=s->next;
	}
	L->next=p;
}
Status ListInsert(LinkList L,int i,ElemType e)
{
	LinkList p;
	p=L;
	int j=1;
	while(p && j<i)
	{
		p=p->next;
		j++;
	}
	if(j>i)
	 return ERROR;
	LinkList s=(LinkList)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
}
void show(LinkList L)
{
	LinkList p=L->next;
	while(p)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
void init(LinkList &L)
{
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
}
int main()
{
	LinkList La,Lb,Lc;
	init(La),init(Lb);
	for(int i=1;i<=10;i++)
	 ListInsert(La,i,i);
	for(int i=11;i<=20;i++)
	 ListInsert(Lb,i-10,i);
	show(La),show(Lb);
	ListReverse(La);
	ListReverse(Lb);
	show(La);show(Lb);
	ListMerge(La,Lb,Lc);
	show(Lc);
	return 0;
}
