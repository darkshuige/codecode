#include<bits/stdc++.h>
using namespace std;
int maxn=1000005;
int sumsum[1000005]={1};
void sum()
{
	int i,j;
	for(i=0;i<1000005;i++)
	 sumsum[i]=1;
	for(i=2;i<=1000005/2;i++)
	{
		for(j=i+i;j<1000005;j+=i)
		{
			sumsum[j]+=i;
		}
	}
}
int main()
{
	sum();
	int l,r;
	while(cin>>l>>r)
	{
		int mm=INT_MIN;
		int i;
		int pos=-1;
		for(i=l;i<=r;i++)
		{
			if(sumsum[i]>mm)
			 {
				mm=sumsum[i];	
				pos=i; 
			 }	
		}
		int count=0;
		if(pos==1)
		{
			cout<<"1 = 1"<<endl;
			continue;
		}
		printf("%d = ",pos);
		for(int j=1;j<=pos/2;j++)
		{
			if(pos%j==0)
			{
				if(count!=0)
				 printf(" + ");
				printf("%d",j);
				count++;
			}
		}
		cout<<endl;
	}
	return 0;
}
