#include<bits/stdc++.h>
using namespace std;
int check(int n)
{
	for(int i=2;i<=sqrt(n);i++)
	 if(n%i==0)
	  return 0;
	return 1;
}
int main()
{
	int n;
	while(cin>>n)
	{
		int sum=0;
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>a;
			if(check(a))
			 sum+=a;
		}
		cout<<sum<<endl;
	}
	return 0;	
} 
