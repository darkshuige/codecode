#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *l,*r;
};
int n,pre[35],in[35],post[35],count=0;
node *creat(int postl,int postr,int inl,int inr)//��������������Ҷ˵�
{
	if(postl>postr)
	 return NULL;//�������г���<0;
	node *root=new node;
	root->data=post[postr];//�� 
	int k;
	for(k=inl;k<=inr;k++)
	{
		if(in[k]==post[postr])//��������������Ҹ� 
		 break;
	}
	int numleft=k-inl;//�������ĸ���
	root->l=creat(postl,postl+numleft-1,inl,k-1);//�ؽ������� 
	root->r=creat(postl+numleft,postr-1,k+1,inr);//�ؽ������� 
	return root;
} 
void bfs(node *root)
{
	queue<node*>q;
	q.push(root);
	while(!q.empty())
	{
		node* cur=q.front();
		q.pop();
		if(::count!=0)
		 cout<<" ";
		::count++;
		cout<<cur->data;
		if(cur->l!=NULL) q.push(cur->l);
		if(cur->r!=NULL) q.push(cur->r);
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	 cin>>post[i];
	for(int i=0;i<n;i++)
	 cin>>in[i];
	node*root=creat(0,n-1,0,n-1);//���� 
	bfs(root);//�������������������� 
	return 0;
} 
