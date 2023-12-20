#include<bits/stdc++.h>
#define QElemType int
#define Status int
#define OK 1
#define OVERLOW 0
#define ERROR 0
using namespace std;
typedef struct QNode
{
	QElemType data;
	struct QNode *ne;
}QNode,*QueuePtr;
typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
Status InitQueue(LinkQueue &Q)
{
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q.front) exit(OVERLOW);
	Q.front->ne=NULL;
	return OK;
}
Status DestroyQueue(LinkQueue &Q)
{
	while(Q.front)
	{
		Q.rear=Q.front->ne;
		free(Q.front);
		Q.front=Q.rear;	
	}	
	return OK;
} 
Status EnQueue(LinkQueue &Q,QElemType e)
{
	QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
	if(!p) exit(OVERLOW);
	p->data=e; p->ne=NULL;
	Q.rear->ne=p;
	Q.rear=p;
	return OK;
}
Status DeQueue(LinkQueue &Q,QElemType &e)
{
	if(Q.front==Q.rear) return ERROR;
	QueuePtr p=Q.front->ne;
	e=p->data;
	Q.front->ne=p->ne;
	if(Q.rear==p) Q.rear=Q.front;
	free(p);
	return OK;
}
signed main()
{
	LinkQueue Q;
	InitQueue(Q);
	for(int i=1;i<=20;i++)
	 EnQueue(Q,i);
	for(int i=0;i<20;i++)
	{
		int e;
		DeQueue(Q,e);
		cout<<e<<endl;
	}
	return 0;
}

