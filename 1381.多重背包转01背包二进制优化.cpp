#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e4+5;
int dp[maxn],s;
int weight[maxn],num[maxn];
int bag1(int w)
{
	for(int i=s;i>=w;i--)
	{
		if(dp[i-w])
		 dp[i]=1;
	}
}
int bag3(int w,int num)
{
	int k=1;
	while(k<=num)
	{
		bag1(w*k);
		num-=k;
	}
	k<<1;//二进制优化 
	bag1(w*num);
}
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0)
		 break;
		s=0;
		memset(dp,0,sizeof dp);
		dp[0]=1;
		for(int i=0;i<n;i++)
		{
			cin>>weight[i]>>num[i];
			s+=weight[i]*num[i];
		}
		for(int i=0;i<n;i++)
		{
			bag3(weight[i],num[i]);
		}
		int id = 1;
        while(dp[id]) 
		 id++;
        cout<<id<<endl;
	}
	return 0;
} 
