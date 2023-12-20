#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int l[20005]={0},x[20005]={0};
	int n,m,i,j,sum,flag=1;
	while(	cin>>n>>m && n && m)
	{
		sum=0;
		for(i=0;i<n;i++)
		 cin>>l[i];
		for(i=0;i<m;i++)
		 cin>>x[i];
		sort(l,l+n);
		sort(x,x+m);
		if(m<n)
		 cout<<"Loowater is doomed!"<<endl;
		else
		{
			flag=1;
			i=0;j=0;
			while(j<n)
			{
				while(x[i]<l[j])
				 i++;
				sum+=x[i];
				i++;
				j++;
				if(m-i<n-j)
				{
					cout<<"Loowater is doomed!"<<endl;
					flag=0;
					break;
				}
			}
			if(flag)
			 cout<<sum<<endl;
		}
		
	}
	
	return 0;
}
