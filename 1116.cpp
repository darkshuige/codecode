#include<bits/stdc++.h> 
using namespace std;
const int maxn=9989899+1;
int prime[maxn];
int judge[maxn];
void init() 
{
	memset(judge,0,sizeof judge);
	int index=0;
    for(int i=2;i<maxn;i++)
    {
    	if(judge[i]==0)
    	 prime[index++]=i;
    	for(int j=0;j<index && prime[j]*i<maxn;j++)
    	{
    		judge[i*prime[j]]=1;
    		if(i%prime[j]==0)
    		 break;
		}
	}
}
bool palindrome(int n) 
{
	int x=0; 
   	int m=n;
   	while(m>0)
    {
		x=x*10+m%10; 
		m=m/10;
    }
	if(x==n)
		return true;
	else
		return false;
	   	
}
int main()
{
	init();
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
    	if(b>maxn)
    	 b=maxn;
	    for(int n=a;n<=b;n++)
		{	
			if(judge[n]==0 && palindrome(n))
			{
	            printf("%d\n",n);
	        }
	    }	
	}
    return 0; 
}
