#include<bits/stdc++.h>
using namespace std;
int check(int a,int b)
{
	int c[10];
	c[0]=a/10;
	c[1]=a%10;
	c[2]=b/100;
	c[3]=b/10%10;
	c[4]=b%10;
	if(c[0]!=0 && c[1]!=0 && c[2]!=0 && c[3]!=0 && c[4]!=0 && c[0]!=c[1] && c[0]!=c[2] && c[0]!=c[3] && c[0]!=c[4] && c[1]!=c[2] &&c[1]!=c[3] &&c[1]!=c[4] &&c[2]!=c[3] &&c[2]!=c[4] &&c[3]!=c[4])
	 return 1;
	else
	 return 0;
}
int main()
{
//	int count=0;
//	for(int i=10;i<=99;i++)
//	{
//		for(int j=100;j<=999;j++)
//		{
//			int a=(i/10*10+j/10%10)*10+i%10;
//			int b=j/100*10+j%10;
//			if(i*j==a*b && check(i,j))
//			{
//				cout<<i<<" "<<j<<" "<<a<<" "<<b<<endl;
//				count++;	
//			}
//		}
//	}
	cout<<142<<endl;
	return 0;
}
