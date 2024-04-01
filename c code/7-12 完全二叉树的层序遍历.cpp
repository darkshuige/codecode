#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	int l,r;
}a[40];
void creat(int i)
{
	if(a[i].l!=0)
	{
		creat(a[i].l);
	}
	if(a[i].r!=0)
	{
		creat(a[i].r);
	}
	cin>>a[i].data;//放在最后是后序遍历 
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(i*2<=n)
		{
			a[i].l=2*i;
		}
		if(i*2+1<=n)
		{
			a[i].r=i*2+1;
		}
	}
	creat(1);
	int count=0;
	for(int i=1;i<=n;i++)
	{
		if(count!=0)
		 cout<<" ";
		count++;
		cout<<a[i].data;
	}
	return 0;
}
