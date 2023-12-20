#include<bits/stdc++.h>
using namespace std;
struct sb
{
	int l,r;
};
int cmp(sb a,sb b)
{
	return a.r<b.r;
}
int main()
{
	int n;
	while(cin>>n)
	{
		sb a[1005];
		for(int i=0;i<n;i++)
		{
			int l,r;
			cin>>l>>r;
			if(l>r)
			 swap(l,r);
			a[i].l=l;
			a[i].r=r;
		}
		sort(a,a+n,cmp);
		int cnt=0;
		int rr=0;
		for(int i=0;i<n;i++)
		{
			if(a[i].l<=rr)
			 cnt++;
			else
			 rr=a[i].r;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
