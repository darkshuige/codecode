#include<bits/stdc++.h>
using namespace std;
typedef enum PointerTag
{
	Link,Thread
};
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild,*rchild;
	PointerTag LTag,RTag;
}BiTNode,*BiTree;
typedef struct BiThrNode
{
	TElemType data;
	struct BiThrNode *lchild,*rchild;
	PointerTag LTag,RTag;
}BiThrNode, *BiThrTree;
Status InOrderTraverse(BiTree T,Status(*Visit)(TElemType e))
{
	InitStack(S);Push(S,T);
	while(!StackEmpty(S))
	{
		while(GetTop(S,p) && p) Push(S,p->lchild);
		Pop(S,p);
		if(!StackEmpty(S))
		{
			Pop(S,p); if(!Visit(p->data)) return ERROR;
			Push(S,p->rchild);
		}
	}
	return OK;
}
Status InOrderTraverse2(BiTree T,Status(*Visit)(TElemType e))
{
	InitStack(S);p=T;
	while(p || !StackEmpty(S))
	{
		if(p)
		 Push(S,p);p=p->lchild;
		else
		{
			Pop(S,p);
			if(!Visit(p->data)) return ERROR;
			p=p->rchild;
		}
	}
	return OK;
}
Status CreateBiTree(BiTree &T)
{
	cin>>ch;
	if(ch=='') T=NULL;
	else
	{
		if(!(T=(BiTNode*)malloc(sizeof(BiTNode)))) exit(OVERFLOW);
		T->data=ch;
		createBiTree(T->lchild);
		createBiTree(T->rchild);
	}
	return OK;
}
Status InOrderTraverse_Thr(BiThrTree T,Status(*Visit)(TElemType e))
{
	p=T->lchild;
	while(p!=T)
	{
		while(p->Ltag==Link) p=p->child;
		if(!Visit(p->data)) return ERROR;
		while(p->RTag==Thread && p->rchild!=T)
		{
			p=p->rchild;
			Visit(p->data);
		}
		p=p->rchild;
	}
	return OK;
}
Status InOrderThreading(BiThrTree &Thrt,BiThrTree T)
{
	if(!(Thrt=*(BiThrTree)malloc(sizeof(BiThrNode)))) exit(OVERFLOW);
	Thrt->LTag=Link;Thrt->RTag=Thread;
	Thrt->rchild=Thrt;
	if(!T) Thrt->lchild=Thrt;
	else
	{
		Thrt->lchild=T;
		pre=Thrt;
		InThreading(T);
		pre->rchild=Thrt;
		pre->RTag=Thread;
		Thrt->rchild=pre;
	}
	return OK;
}
void InThreading(BiThrTree p)
{
	if(p)
	{
		InThreading(p->lchild);
		if(!p->lchild)
		{
			p->LTag=Thread;
			p->lchild=pre;
		}
		if(!pre->rchild)
		{
			pre->RTag=Thread;
			pre->rchild=p;
		}
		pre=p;
		InThreading(p->rchild);
	}
}
int main()
{
	
	return 0;
}
