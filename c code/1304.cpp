#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		int a[105]={0};
		int b[105]={0};
		int i;
		for(i=0;i<n;i++)
		 cin>>a[i];
		for(i=0;i<m;i++)
		 cin>>b[i];
		sort(a,a+n);
		sort(b,b+m);
		int j;
		int flag=0;
		for(j=m-1;j>=0 && flag==0;j--)
		{
			for(i=0;i<n && flag==0;i++)
			{
				if((3*a[i]<=2*b[j] && 2*b[j]<=4*a[i]) || (3*b[j]<=2*a[i] && 2*a[i]<=4*b[j]))
				{
					flag=1;
				}
			}
		}
		if(flag)
		 cout<<"Yes"<<endl;
		else
		 cout<<"No"<<endl;
	}
	return 0;
}
