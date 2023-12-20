#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int count=0;
		int a=0,b=0,c=0;
		int sum=0;
		for(int i=0;i<n;i++)
		{
			sum=0;
			cin>>a>>b>>c;
			sum+=a+b+c;	
			if(sum>=2)
			 count++;
		}
		cout<<count<<endl;
	}
	return 0;
}
