#include<iostream>
using namespace std;
struct treenode
{
	char shu;
	int left;
	int right;
};
struct treenode tree1[10],tree2[10];
int buildtree(struct treenode t[])
{
	int n,i;
	int check[10]={0};
	char a,l,r;
	int root;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a>>l>>r;
		t[i].shu=a;t[i].left=(l-'0');t[i].right=(r-'0');
		if(l=='-')
		{
			t[i].left=-1;
		}
		if(r=='-')
		{
			t[i].right=-1;
		}
	}
	for(i=0;i<n;i++)
	{
		if(t[i].left!=-1)
		 check[t[i].left]++;
		if(t[i].right!=-1)
		 check[t[i].right]++; 
	}
	for(i=0;i<n;i++)
	 if(check[i]==0)
	  break;
	root=i;
	return root;
}
int isthetree(int r1,int r2)
{
	if(r1==-1 && r2==-1)
	 return 1;
	if((r1==-1 && r2!=-1) || (r1!=-1 && r2==-1))
	 return 0;
	if(tree1[r1].shu != tree2[r2].shu)
	 return 0;
	if(tree1[r1].left==-1 && tree2[2].left==-1)
	 return isthetree(tree1[r1].right,tree2[r2].right);
	if((tree1[r1].left!=-1 && tree2[r2].left!=-1) && (tree1[tree1[r1].left].shu==tree2[tree2[r2].left].shu))
	 return (isthetree(tree1[r1].left,tree2[r2].left) && isthetree(tree1[r1].right,tree2[r2].right));
	else
	 return (isthetree(tree1[r1].left,tree2[r2].right) && isthetree(tree1[r1].right,tree2[r2].left));
}
int main()
{
	int r1,r2;
	r1=buildtree(tree1);
	r2=buildtree(tree2);
	if(isthetree(r1,r2))
	 cout<<"YES"<<endl;
	else
	 cout<<"NO"<<endl;
} 
