#include<bits/stdc++.h>
using namespace std;
const int maxn=30;
struct node
{
	char data;
	node *l,*r;
};
int n;
char pre[maxn],in[maxn],post[maxn];
node *creat(int prel,int prer,int inl,int inr)
{
	if(prel>prer)
	 return NULL;
	node *root=new node;
	root->data=pre[prel];
	int k;
	for(k=inl;k<=inr;k++)
	{
		if(in[k]==pre[prel])
		 break;
	}
	int num=k-inl;
	root->l=creat(prel+1,prel+num,inl,k-1);
	root->r=creat(prel+1+num,prer,k+1,inr);
	return root;
}
void bfs(node *root)
{
	if(root->l!=NULL) bfs(root->l);
	if(root->r!=NULL) bfs(root->r);
	cout<<root->data;
}
int main()
{
	while(cin>>pre>>in)
	{
		n=strlen(pre);
		node *root=creat(0,n-1,0,n-1);
		bfs(root);
		cout<<endl;
	}
	return 0;
} 
