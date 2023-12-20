#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		if(a==0 && b==0)
		 break;
		int count=0;
		for(int i=0;i<=99;i++)
		{
			
			int a1=a*100+i;
			if(a1%b==0)
			{
				if(count!=0)
				 cout<<" ";
				printf("%02d",i);
				count++;
			}
		}
		cout<<endl;
	}
	return 0;
}
