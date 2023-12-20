#include<bits/stdc++.h>
using namespace std;
int act(int n)
{
	int a[10]={0};
	int k=0;
	int flag=0;
	if(n<0)
	{
		flag=1;
		n=-n;
	}
	while(n)
	{
		a[k++]=n%10;
		n/=10;
	}
	int i=0;
	while(a[i]==0)
	 i++;
	int ans=0;
	for(i;i<k;i++)
	{
		ans=ans*10+a[i];
	}
	if(flag)
	 ans=-ans;
	return ans;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x,y,a,b;
		cin>>x>>y;
		a=(x+y)>>1;
		b=(x-y)>>1;
		a=act(a);
		b=act(b);
		cout<<a+b<<" "<<a-b<<endl;
	}
	return 0;
} 
