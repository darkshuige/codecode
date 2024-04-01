#include<bits/stdc++.h>
using namespace std;
int act(long long n)
{
	int ans=0;
	while(n)
	{
		n/=10;
		ans++;
	}
	return ans;
}
int main()
{
	long long n;
	cin>>n;
	int ws=act(n);
	int sum=0;
	sum+=(ws-1)*9;
	long long k=0;
	for(int i=0;i<ws;i++)
	 k=k*10+1;
	if(n>=k)
	 sum++;
	k=0;
	for(int i=0;i<ws;i++)
	 k=k*10+2;
	if(n>=k)
	 sum++;
	k=0;
	for(int i=0;i<ws;i++)
	 k=k*10+3;
	if(n>=k)
	 sum++;
	k=0;
	for(int i=0;i<ws;i++)
	 k=k*10+4;
	if(n>=k)
	 sum++;
	k=0;
	for(int i=0;i<ws;i++)
	 k=k*10+5;
	if(n>=k)
	 sum++;
	k=0;
	for(int i=0;i<ws;i++)
	 k=k*10+6;
	if(n>=k)
	 sum++;
	k=0;
	 for(int i=0;i<ws;i++)
	 k=k*10+7;
	if(n>=k)
	 sum++;
	k=0;
	for(int i=0;i<ws;i++)
	 k=k*10+8;
	if(n>=k)
	 sum++;
	k=0;
	for(int i=0;i<ws;i++)
	 k=k*10+9;
	if(n>=k)
	 sum++;
	k=0;
	cout<<sum<<endl;
	return 0;
} 
