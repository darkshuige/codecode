#include<bits/stdc++.h>
#define QElemType int
#define Status int
#define OK 1
#define OVERLOW 0
#define ERROR 0
#define MAXQSIZE 100
using namespace std;
typedef struct
{
	QElemType *base;
	int front;
	int rear;
	int frear;
	int rfront;
}SqQueue;
Status InitQueue (SqQueue &Q)
{
	Q.base=(QElemType *)malloc(MAXQSIZE * sizeof (QElemType));
	if(!Q.base) exit(OVERLOW);
	Q.front=Q.rear=0;
	Q.frear=Q.rfront=MAXQSIZE-1;
	return OK;
}
int QueueLength(SqQueue Q)
{
	return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}
Status EnQueue1(SqQueue &Q,QElemType e)
{
	if((Q.rear+1)%MAXQSIZE==Q.front) return ERROR;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXQSIZE;
	Q.rfront=(Q.rfront+1)%MAXQSIZE;
}
Status EnQueue2(SqQueue &Q,QElemType e)
{
	if((Q.frear-1+MAXQSIZE)%MAXQSIZE==Q.rfront) return ERROR;
	Q.base[Q.frear]=e;
	Q.frear=(Q.frear-1+MAXQSIZE)%MAXQSIZE;
	Q.front=(Q.front-1+MAXQSIZE)%MAXQSIZE;
}
Status empty(SqQueue &Q)
{
	if(Q.rear==Q.front)
	 return 1;
	else
	 return 0;
}
Status show_front(SqQueue &Q)
{
	return Q.base[Q.front];
}
Status show_rfront(SqQueue &Q)
{
	return Q.base[Q.rfront];
}
void show(SqQueue &Q)
{
	while(Q.front!=Q.rear)
	{
		cout<<Q.base[Q.front]<<" ";
		Q.front=(Q.front+1)%MAXQSIZE;
	}
}
signed main()
{
	SqQueue Q;
	InitQueue(Q);
	EnQueue1(Q,10);
	for(int i=1;i<=20;i++)
	{
		if(i*2<show_front(Q)+show_rfront(Q))
		 EnQueue1(Q,i);
		else
		 EnQueue2(Q,i);
	}
	show(Q);
	return 0;
}

