#include<iostream>
using namespace std;
int main()
{
	int a[100005]={0};
	int n,k,s,i,t,l,count=0;
	cin>>n>>k>>s;
	for(i=0;i<s;i++)
	{
		cin>>t>>l;
		a[t]+=l;
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]<k)
		 count++;
	}
	cout<<count<<endl;
	return 0;
}
