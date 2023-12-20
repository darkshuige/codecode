#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *l,*r;
};
int n,pre[1000],in[1000],post[1000],cc=0;
node *creat(int prel,int prer,int inl,int inr)
{
	if(prel>prer)
	{
		return NULL;
	}
	node *root=new node;
	root->data=pre[prel];
	int k;
	for(k=inl;k<=inr;k++)
	{
		if(in[k]==pre[prel])
		 break;
	}
	int numleft=k-inl;
	root->l=creat(prel+1,prel+numleft,inl,k-1);
	root->r=creat(prel+numleft+1,prer,k+1,inr);
	return root;
}
void bl(node *root)
{
	if(root->l!=NULL && root->r==NULL)
	{
		bl(root->l);
		if(cc!=0)
		 cout<<" ";
		cout<<root->data;
		cc++;
	}
	else if(root->r!=NULL && root->l==NULL)
	{
		bl(root->r);
		if(cc!=0)
		 cout<<" ";
		cout<<root->data;
		cc++;
	}
	else if(root->l!=NULL && root->r!=NULL)
	{
		bl(root->l);
		bl(root->r);
		if(cc!=0)
		 cout<<" ";
		cout<<root->data;
		cc++;
	}
	else if(root->l==NULL && root->r==NULL)
	{
		if(cc!=0)
		 cout<<" ";
		cout<<root->data;
		cc++;
	}
}
int main()
{
	while(cin>>n)
	{
		cc=0;
		for(int i=0;i<n;i++)
		 cin>>pre[i];
		for(int i=0;i<n;i++)
		 cin>>in[i];
		node *root=creat(0,n-1,0,n-1);
		bl(root);
		cout<<endl;
	}
	return 0;
}
