#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *l,*r;
};
node *creat(int x,node *root)
{
	if(root==NULL)
	{
		root=new node;
		root->data=x;
		root->l=NULL;
		root->r=NULL;
	}
	else if(x<root->data)
	 root->l=creat(x,root->l);
	else if(x>root->data)
	 root->r=creat(x,root->r);
	return root;
}
void pre_dfs(node *root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		pre_dfs(root->l);
		pre_dfs(root->r);
	}
}
void in_dfs(node *root)
{
	if(root!=NULL)
	{
		in_dfs(root->l);
		cout<<root->data<<" ";
		in_dfs(root->r);
	}
}
void post_dfs(node *root)
{
	if(root!=NULL)
	{
		post_dfs(root->l);
		post_dfs(root->r);
		cout<<root->data<<" ";
	}
}
int main()
{
	int n;
	while(cin>>n)
	{
		node *root=NULL;
		for(int i=0;i<n;i++)
		{
			int op;
			cin>>op;
			root=creat(op,root);
		}
		pre_dfs(root);
		cout<<endl;
		in_dfs(root);
		cout<<endl;
		post_dfs(root);
		cout<<endl;
	}
	return 0;
}
