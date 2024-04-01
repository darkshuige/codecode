#include<bits/stdc++.h>
using namespace std;
struct sb
{
	int pos1,data,pos2;	
};
int cmp1(sb a,sb b)
{
	return a.data<b.data;
}
int cmp2(sb a,sb b)
{
	return a.pos1<b.pos1;
}
int main()
{
	int n;
	while(cin>>n)
	{
		sb a[10005];
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].data;
			a[i].pos1=i;
		}
		sort(a+1,a+1+n,cmp1);
		for(int i=1;i<=n;i++)
		 a[i].pos2=i;
		sort(a+1,a+1+n,cmp2);
		for(int i=1;i<=n;i++)
		{
			if(i!=1)
			 cout<<" ";
			cout<<a[i].pos2;
		}
		cout<<endl;
	}
	return 0;
}
