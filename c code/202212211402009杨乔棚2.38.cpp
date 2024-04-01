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
	int freq;
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
	L->freq=0;
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
	s->freq=0;
	s->pre=p;
	p->next=s;
	s->next=L;
	L->pre=s;
}
Status LOCATE(DuLinkList &L,int x)
{
    DuLinkList p,q;   
    if(!L)	return ERROR;
    p = L->next;
    q = L->next;
    while(p != L && p->data != x)
     p=p->next;
    if(p == L)	
	 return 0;
    p->freq++;	
    p->pre->next=p->next;
    p->next->pre=p->pre; 
    while(q != L && q->freq >= p->freq)
     q = q->next;
    if(q == L)
	{
        p->next=q->next;
        q->next=p;
        p->pre=q->pre;
        q->pre=p;
    }
    else
	{
        p->next = q->pre->next;
        q->pre->next = p;
        p->pre = q->pre;
        q->pre = p;
    }
    return OK;  
}
signed main()
{
	
	DuLinkList L;init(L);
	for(int i=1;i<20;i++)
	 ins(L,i,i);
	show(L);
	LOCATE(L,10);
	show(L);
	LOCATE(L,12);
	show(L);
	return 0;
}
