#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *l,*r;
};
int n,pre[35],in[35],post[35],count=0;
node *creat(int postl,int postr,int inl,int inr)//后续与中序的左右端点
{
	if(postl>postr)
	 return NULL;//后序序列长度<0;
	node *root=new node;
	root->data=post[postr];//根 
	int k;
	for(k=inl;k<=inr;k++)
	{
		if(in[k]==post[postr])//在中序遍历里面找根 
		 break;
	}
	int numleft=k-inl;//左子树的个数
	root->l=creat(postl,postl+numleft-1,inl,k-1);//重建左子树 
	root->r=creat(postl+numleft,postr-1,k+1,inr);//重建右子树 
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
	node*root=creat(0,n-1,0,n-1);//建树 
	bfs(root);//宽度优先搜索，层序遍历 
	return 0;
} 
