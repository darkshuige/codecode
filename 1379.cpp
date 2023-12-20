#include<bits/stdc++.h>
using namespace std;
void getin(int n,int a[])
{
	a[3]=n%10;
	n/=10;
	a[2]=n%10;
	n/=10;
	a[1]=n%10;
	n/=10;
	a[0]=n%10;
}
int getout(int a[])
{
	int sum=0;
	for(int i=0;i<=3;i++)
	sum=sum*10+a[i];
	return sum;
}
int cmp1(const int a,const int b)
{
	return a>b;
}
int cmp2(const int a,const int b)
{
	return a<b;
}
int main()
{
	int n;
	while(cin>>n)
	{
		int a[4];
		getin(n,a);
		if(a[0]==a[1] && a[1]==a[2] && a[2]==a[3])
		{
			printf("%d - %d = 0000\n",n,n);
			continue;
		}
		int sum1,sum2;
		do
		{
			sort(a,a+4,cmp1);
			sum1=getout(a);
			sort(a,a+4,cmp2);
			sum2=getout(a);
			printf("%04d - %04d = %04d\n",sum1,sum2,sum1-sum2);
			getin(sum1-sum2,a);
		}
		while(sum1-sum2!=6174);
	}
	return 0;	
} 
