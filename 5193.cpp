#include<bits/stdc++.h>
using namespace std;
int a[20000000];
int main()
{
	int m;
	int k=0;
	while(cin>>m)
	{
		k++;
		memset(a,0,sizeof a);
		if(m==0)
		 break;
		int pos=0;
		for(int i=0;i<m;i++)
		{
			int op,b;
			cin>>op>>b;
			for(int j=0;j<b;j++)
			 a[pos++]=op;
		}
		sort(a,a+pos);
		long long sum1=0,sum2=0;
		int pos1=(0+pos)/2,pos2=pos1+1;
		for(int i=0;i<pos;i++)
		{
			sum1+=abs(a[i]-a[pos1]);
			sum2+=abs(a[i]-a[pos2]);
		}
		printf("Case %d: ",k);
		if(sum1<sum2)
		 cout<<sum1<<endl;
		else
		 cout<<sum2<<endl;
	}
    return 0;
}
