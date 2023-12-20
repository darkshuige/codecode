#include<iostream>
using namespace std;
int y[]={-1,0,1,-1,0,1,-1,0,1};
int x[]={-1,-1,-1,0,0,0,1,1,1};
int n,m;
int a[105][105]={0};
void find(int i,int j)
{
	int k,count=0;
	for(k=0;k<9;k++)
	{
		if(i+x[k]<n && i+x[k]>=0 && j+y[k]<m && j+y[k]>=0)
		{
			if(a[i+x[k]][j+y[k]]==9)
			 count++;
		}
	}
	a[i][j]=count;
}
int main()
{
	while(cin>>n>>m)
	{
		int i,j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				cin>>a[i][j];
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(a[i][j]==-1)
				{
					find(i,j);
				}
				cout<<a[i][j];
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
