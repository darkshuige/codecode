#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int k,j;
	cin>>k;
	for(j=0;j<k;j++)
	{
		int i,n;
		double count1=0,count2=0;
		int cj;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>cj;
			if(cj>=60)
			{
				count1++;
			}
			count2++;
		}	
		printf("%.3f\%\n",count1/count2*100);
		cout<<endl;
	}
	
	
	return 0;
}
