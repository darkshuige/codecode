#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			string a;
			cin>>a;
			int sum1=0,sum2=0,sum3=0,sum4=0,j;
			j=0;
			sum1=(a[j]-48)*pow(2,7)+(a[j+1]-48)*pow(2,6)+(a[j+2]-48)*pow(2,5)+(a[j+3]-48)*pow(2,4)+(a[j+4]-48)*pow(2,3)+(a[j+5]-48)*pow(2,2)+(a[j+6]-48)*pow(2,1)+(a[j+7]-48)*pow(2,0);
			j=8;
			sum2=(a[j]-48)*pow(2,7)+(a[j+1]-48)*pow(2,6)+(a[j+2]-48)*pow(2,5)+(a[j+3]-48)*pow(2,4)+(a[j+4]-48)*pow(2,3)+(a[j+5]-48)*pow(2,2)+(a[j+6]-48)*pow(2,1)+(a[j+7]-48)*pow(2,0);
			j=16;
			sum3=(a[j]-48)*pow(2,7)+(a[j+1]-48)*pow(2,6)+(a[j+2]-48)*pow(2,5)+(a[j+3]-48)*pow(2,4)+(a[j+4]-48)*pow(2,3)+(a[j+5]-48)*pow(2,2)+(a[j+6]-48)*pow(2,1)+(a[j+7]-48)*pow(2,0);
			j=24;
			sum4=(a[j]-48)*pow(2,7)+(a[j+1]-48)*pow(2,6)+(a[j+2]-48)*pow(2,5)+(a[j+3]-48)*pow(2,4)+(a[j+4]-48)*pow(2,3)+(a[j+5]-48)*pow(2,2)+(a[j+6]-48)*pow(2,1)+(a[j+7]-48)*pow(2,0);
			printf("%d.%d.%d.%d\n",sum1,sum2,sum3,sum4);
		}
	}
	return 0;
}
