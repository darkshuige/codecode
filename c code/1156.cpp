#include<iostream>
#include<cstring>
using namespace std;
bool a[1000005]={0};
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		memset(a,0,sizeof a);
		int i;
		for(i=0;i<m;i++)
		{
			int x;
			cin>>x;
			int l,r;
			cin>>l>>r;
			if(x==1)
			{
				int j;
				for(j=l;j<=r;j++)
				 a[j]=!a[j];	
			}
			else if(x==0)
			{
				int j;
				for(j=l;j<=r;j++)
				 cout<<a[j];
				cout<<endl;
			}
			 
		}
	}
	return 0;
} 
