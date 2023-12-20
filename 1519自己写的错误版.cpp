#include<bits/stdc++.h>
using namespace std;
int cmp(string a,string b)
{
	return a<b;
}
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		string a[100005];
		int n;
		cin>>n;
		for(int j=0;j<n;j++)
		 a[j]="";
		for(int j=0;j<n;j++)
		 cin>>a[j];
		sort(a,a+n,cmp);
		for(int j=0;j<n-1;j++)
		{
			string sp1=a[j]+a[j+1];
			string sp2=a[j+1]+a[j];
			if(sp1>sp2)
			 swap(a[j],a[j+1]);
		}
		int pos=0;
		int k=0;
		int flag=0;
		while(a[k][pos]=='0')
		{
			pos++;
			if(pos>=a[k].size())
			{
				pos-=a[k].size();
				k++;
			}
			if(k>=n)
			{
				flag=1;
				break;
			}
		}
		if(flag)
		 cout<<0<<endl;
		else
		{
			for(pos;pos<a[k].size();pos++)
			  cout<<a[k][pos];
			for(k=k+1;k<n;k++)
			 cout<<a[k];
			cout<<endl;	
		}
	}	
	return 0;
}
