#include<bits/stdc++.h>
using namespace std;
struct node
{
	char data;
	node *l,*r;
};
node *creat(node *root,char x)
{
	if(root==NULL)
	{
		root=new node;
		root->data=x;
		root->l=NULL;
		root->r=NULL;
	}
	else
	{
		if(x<root->data)
		 root->l=creat(root->l,x);
		else
		 root->r=creat(root->r,x);
	}
	return root;
}
void pre_dfs(node *root,string& s)
{
	if(root!=NULL)
	{
		s+=root->data;
//		cout<<"sµÄÖµÊÇ"<<s<<endl;
		pre_dfs(root->l,s);
		pre_dfs(root->r,s);
	}
}
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0)
		 break;
		node *root=NULL;
		string s;
		cin>>s;
		for(int i=0;i<s.size();i++)
		 root=creat(root,s[i]);
		string res1="";
		pre_dfs(root,res1);
		for(int i=0;i<n;i++)
		{
			cin>>s;
			node *root1=NULL;
			for(int i=0;i<s.size();i++)
			 root1=creat(root1,s[i]);
			string res2="";
			pre_dfs(root1,res2);
			if(res1==res2)
			 cout<<"YES"<<endl;
			else
			 cout<<"NO"<<endl;
		}	
	}
	
	return 0;
} 
