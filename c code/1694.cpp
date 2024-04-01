#include<bits/stdc++.h>
using namespace std;
int cmp(const int a,const int b)
{
	return a>b;
}
int main()
{
	int n;
	while(cin>>n)
	{
		int m;
		cin>>m;
		int a[105]={0};
		for(int i=0;i<n;i++)
		 cin>>a[i];
		sort(a,a+n,cmp);		
		int count=0;
		while(m>0)
		{
			m-=a[count];
			count++;
		}
		cout<<count<<endl;
	}
	return 0;
} 
