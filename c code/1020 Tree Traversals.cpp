#include<bits/stdc++.h>
using namespace std;
const int maxn=30;
struct node
{
	int data;
	node *l,*r;
};
int n;
int pre[maxn],in[maxn],post[maxn];
map<int,int>mp;
vector<int>ans;
node *creat(int l1,int r1,int l2,int r2)
{
	if(l1>r1)
	 return NULL;
	node *root=new node;
	root->data=post[r2];
	int pos=mp[post[r2]];
	root->l=creat(l1,pos-1,l2,l2-1+(pos-l1));
	root->r=creat(pos+1,r1,r2+pos-r1,r2-1);
	return root;
}
void bfs(node *root)
{
	queue<node*>q;
	q.push(root);
	while(!q.empty())
	{
		auto root=q.front(); q.pop();
		ans.push_back(root->data);
		if(root->l!=NULL) q.push(root->l);
		if(root->r!=NULL) q.push(root->r);
	}

}
int main()
{
	int n; cin>>n;
	for(int i=0;i<n;i++) cin>>post[i];
	for(int i=0;i<n;i++)
	{
		cin>>in[i];
		mp[in[i]]=i;
	}
 	node *root=creat(0,n-1,0,n-1);
	bfs(root);
	for(int i=0;i<ans.size();i++)
	{
		if(i!=0) cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
} 
