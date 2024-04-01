#include<bits/stdc++.h>
using namespace std;
bool check(int a)
{
	for(int i=2;i<=sqrt(a);i++)
	 if(a%i==0)
	  return 0;
	return 1;
}
int main()
{
	int n;
	while(cin>>n)
	{
		int count=0;
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>a;
			if(check(a))
			 count+=a;			
		}
		cout<<count<<endl;
	}
	return 0;
}
