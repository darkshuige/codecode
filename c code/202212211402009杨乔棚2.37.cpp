#include<bits/stdc++.h>
#define ELemType int
#define OK 1
#define ERROR 0
#define Status int
using namespace std;
typedef struct DuLNode
{
	ELemType data;
	struct DuLNode *pre;
	struct DuLNode *next;
	
}DuLNode,*DuLinkList; 
DuLinkList GetElemP_DuL(DuLinkList &L,int i)
{
	DuLinkList p=L->next;
	for(int j=1;j<i;j++)
	{
		p=p->next;
	}
	return p;
}
Status ListInsert_DuL(DuLinkList &L,int i,ELemType e)
{
	DuLinkList p=GetElemP_DuL(L,i);
	DuLinkList s;
	if(!(s=(DuLinkList)malloc(sizeof(DuLNode)))) return ERROR;
	s->data=e;
	s->pre=p->pre;
	p->pre->next=s;
	s->next=p;
	p->pre=s;
	return OK;
} 
void Reform(DuLinkList &L)
{ 
	DuLinkList p=L->next; 
	while(p->next!=L && p->next->next!=L) 
	{ 
		p->next=p->next->next; 
		p=p->next; 
	}  
	if(p->next==L) 
	 p->next=L->pre->pre; 
	else
	 p->next=L->pre; 
	p=p->next; 
	while(p->pre->pre!=L) 
	{ 
		p->next=p->pre->pre; 
		p=p->next; 
	} 
	p->next=L;
	for(p=L;p->next!=L;p=p->next) 
	 p->next->pre=p; 
	L->pre=p;
}
DuLinkList init(DuLinkList &L)
{
	L=(DuLinkList)malloc(sizeof(DuLNode));
	L->next=NULL;
	L->pre=NULL;
}
void show(DuLinkList &L)
{
	DuLinkList p=L->next;
	while(p && p!=L)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
void ins(DuLinkList &L,int i,int e)
{
	DuLinkList p=L;
	for(int j=1;j<i;j++)
	 p=p->next;
	DuLinkList s;
	s=(DuLinkList)malloc(sizeof(DuLNode));
	s->data=e;
	s->pre=p;
	p->next=s;
	s->next=L;
	L->pre=s;
}
signed main()
{
	
	DuLinkList L;init(L);
	for(int i=1;i<20;i++)
	 ins(L,i,i);
	show(L);
	Reform(L);
	show(L);
	return 0;
}
