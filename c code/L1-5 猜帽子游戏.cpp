#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[110]={0};
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int flag1=0;//表示猜对 
		int flag2=0;//表示猜错 
		for(int j=0;j<n;j++)
		{
			int as;
			cin>>as;
			if(as!=0 && as!=a[j])
			{
				flag2=1;
			}
			if(as==a[j])
			{
				flag1=1;
			}
		}
		if(flag1 && flag2==0)
		 cout<<"Da Jiang!!!"<<endl;
		else if(flag2 || (flag1==0 && flag2==0))
		 cout<<"Ai Ya"<<endl;
	}
	return 0;
} 
