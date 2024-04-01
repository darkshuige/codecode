#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	while(cin>>n>>k)
	{
		int sum=1;
		if(k>n)
		{
			cout<<"0"<<endl;
			continue;
		}
		else if(k==1)
		{
			cout<<n*n<<endl;
			continue;
		}
		else
		{
			int i;
			for(i=0;i<k;i++)
			{
				sum*=(n-i);
			}
			if(n!=k)
			 sum=sum*(n-i+1)*(n-k);
		}
		cout<<sum<<endl;
	}
	return 0;
} 
