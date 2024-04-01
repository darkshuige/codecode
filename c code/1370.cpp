#include<bits/stdc++.h>
using namespace std;
struct sb
{
	int first,second,th;
};
int cmp(sb a,sb b)
{
	return a.th>b.th;
}
int main()
{
	int n;
	while(cin>>n)
	{
		sb a[100005];
		for(int i=0;i<n;i++)
		{
			cin>>a[i].first>>a[i].second;
			a[i].th=a[i].first-a[i].second;
		}
		sort(a,a+n,cmp);
		int sum=0;
		int maxn=INT_MIN;
		for(int i=0;i<n;i++)
		{
			if(a[i].first+sum>maxn)
			 maxn=a[i].first+sum;
			sum+=a[i].second;
		}
		cout<<maxn<<endl;
	}
	return 0;
}
