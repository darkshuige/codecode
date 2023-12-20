#include <bits/stdc++.h>
using namespace std;
typedef enum Tag
{
	Ptr,Thread
}PointerTag;
typedef struct ThreadTreeNode
{
	char data; 				
	struct ThreadTreeNode* lchild;  
	struct ThreadTreeNode* rchild; 
	PointerTag LTag;  			
	PointerTag RTag;			
}Tnode,*Ttree;
Ttree pre;
void createBiTree(Ttree& T)
{
	char ch;
	cin>>ch;
	if(ch=='#')	T=NULL;
	else
	{
		if(!(T=(Tnode*)malloc(sizeof(Tnode))))  exit(0);
		T->data=ch;
		T->LTag=Ptr;
		T->RTag=Ptr;
		createBiTree(T->lchild); 
		createBiTree(T->rchild);
	}
}
void visit(char data)
{
	cout<<data;
}
void inOrderTraverse(Ttree Thrt)
{
	Ttree p;
	p=Thrt->lchild;
	while(p!=Thrt)
	{
		while(p->LTag==Ptr)
		{
			p=p->lchild; 
		}
		visit(p->data);
		cout<<p->LTag<<p->RTag<<endl;
		while(p->RTag==Thread&&p->rchild!=Thrt)
		{
			p=p->rchild;
			visit(p->data);
			cout<<p->LTag<<p->RTag<<endl;
		}
		p=p->rchild;
	}
}
void inThreading(Ttree p)
{
	if(p)
	{ 
		inThreading(p->lchild);
		visit(p->data);
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
		inThreading(p->rchild); 
	}
} 
void inOrderThreadTree(Ttree& Thrt,Ttree T)
{
	if(!((Thrt)=(Ttree)malloc(sizeof(Tnode))))  exit(0);
	Thrt->LTag=Ptr;			
	Thrt->RTag=Thread;			
	Thrt->rchild=Thrt;  	
	if(!T)  Thrt->lchild=Thrt; 
	else						 
	{
		Thrt->lchild=T;			
		pre=Thrt;				
		inThreading(T);		 
		pre->rchild=Thrt;	
		pre->RTag=Thread;		
		Thrt->rchild=pre; 
	}
}
int main()
{
	Ttree Thrt;  
	Ttree T;  	 
	createBiTree(T);
	inOrderThreadTree(Thrt,T);
	cout<<endl;
	inOrderTraverse(Thrt);
	return 0;
} 
