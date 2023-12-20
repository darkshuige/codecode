#include<bits/stdc++.h>
using namespace std; 
int main()
{
	int n;
	int t=0;
	while(cin>>n)
	{
		t++;
		int sum=0;
		int a[100]={0};
		if(n==0) break;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		int ave=sum/n;
		int count=0;
		for(int i=0;i<n;i++)
		{
			if(ave>a[i])
			 count=count+abs((a[i]-ave));
		}
		printf("Set #%d\n",t);
		printf("The minimum number of moves is %d.\n\n",count);
	}
	return 0;
}
