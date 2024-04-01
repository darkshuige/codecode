#include<bits/stdc++.h>
using namespace std;
int op[]={1,0,0,0,0,0,1,0,2,1};
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		int len=s.size();
		int sum=0;
		for(int j=0;j<len;j++)
		{
			sum+=op[s[j]-'0'];
		}
		cout<<sum<<endl;
	}
	return 0;
} 
