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
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int flag=1;
		int v,n;
		cin>>v>>n;
		sb p[1005];
		for(int j=0;j<n;j++)
		{
			cin>>p[j].first>>p[j].second;
			p[j].th=p[j].second-p[j].first;
		}
		sort(p,p+n,cmp);
		for(int j=0;j<n;j++)
		{
			if(v>=p[j].second && v>=p[j].first)
			{
				v-=p[j].first;
			}
			else
			{
				flag=0;
				break;
			}
		}
		if(flag)
		 cout<<"Yes"<<endl;
		else
		 cout<<"No"<<endl;
	}
	return 0;
} 
