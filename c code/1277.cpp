#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,pos;
	while(cin>>n>>pos)
	{
		int a[1005]={0};
		int sum=0;
		int pos1=INT_MAX,pos2=INT_MIN;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]!=0 && i<pos1)
			 pos1=i;
			if(a[i]!=0 && i>pos2)
			 pos2=i;
			sum+=a[i];
		}
		if(pos1!=INT_MAX && pos2!=INT_MIN)
		{
			if(pos<=pos1)
			{
				sum+=pos2-pos;
			}
			else if(pos>=pos2)
			{
				sum+=pos-pos1;
			}
			else
			{
				sum=sum+min(pos-pos1,pos2-pos)+pos2-pos1;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
} 
