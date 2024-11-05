#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int isf(int k)
{
	if(k==0 || k==1) return 0;
	for(int i=2;i<k;i++)
	 if(k%i==0)
	  return 0;
	return 1;
}
int sanif(int k)
{
	if(isf(k%10)==0)
	 return 0;
	k/=10;
	if(isf(k%10)==0)
	 return 0;
	k/=10;
	if(isf(k%10)==0)
	 return 0;
	return 1;
}
int erif(int k)
{
	if(isf(k%10)==0)
	 return 0;
	k/=10;
	if(isf(k%10)==0)
	 return 0;
	return 1;
}
int wuif(int k)
{
	if(isf(k%10)==0)
	 return 0;
	k/=10;
	if(isf(k%10)==0)
	 return 0;
	k/=10;
	if(isf(k%10)==0)
	 return 0;
	k/=10;
	if(isf(k%10)==0)
	 return 0;
	k/=10;
	if(isf(k%10)==0)
	 return 0;
	return 1;
}
int siif(int k)
{
	if(isf(k%10)==0)
	 return 0;
	k/=10;
	if(isf(k%10)==0)
	 return 0;
	k/=10;
	if(isf(k%10)==0)
	 return 0;
	k/=10;
	if(isf(k%10)==0)
	 return 0;
	return 1;
}
signed main()
{
	for(int i=100;i<=999;i++)
	{
		for(int j=10;j<=99;j++)
		{
			if(sanif(i) && erif(j) && wuif(i*j) && siif(i*(j%10)) && siif(i*(j/10%10)))
			{
				cout<<i<<" "<<j<<endl;
				cout<<i*j<<endl;
			}
		}
	}
	return 0;
}