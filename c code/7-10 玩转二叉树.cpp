#include<bits/stdc++.h>
using namespace std;
int n,post[35],in[35];
struct node
{
	int data;
	node *l,*r;
};
node *creat(int postl,int postr,int inl,int inr)
{
	if(postl>postr)
	 return NULL;
	node *root=new node;
	root->data=post[postl];
	int i;
	for(i=inl;i<=inr;i++)
	 if(in[i]==post[postl])
	  break;
	int lifenum=i-inl;
	root->l=creat(postl+1,postl+lifenum,inl,i-1);
	root->r=creat(postl+lifenum+1,postr,i+1,inr);
	return root;
}
int ct=0;
void bfs(node *root)
{
	queue<node*>q;
	q.push(root);
	while(!q.empty())
	{
		node *cur=q.front();
		q.pop();
		if(ct!=0)
		 cout<<" ";
		ct++;
		cout<<cur->data;
		if(cur->r!=NULL) q.push(cur->r);
		if(cur->l!=NULL) q.push(cur->l);
	}
}
int main()
{
	int postl,postr,inl,inr;
	cin>>n;
	for(int i=0;i<n;i++)
	 cin>>in[i];
	for(int i=0;i<n;i++)
	 cin>>post[i];
	node *root=creat(0,n-1,0,n-1);
	bfs(root);
	return 0;
}
