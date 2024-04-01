#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while(cin>>s)
	{
		int a[27]={0};
		int i;
		int sum=0;
		for(i=0;i<s.size();i++)
		{
			if(a[(int)s[i]-97]==0)
			{
				a[(int)s[i]-97]=1;
				sum++;	
			}
		}
		if(sum%2!=0)
		{
			cout<<"IGNORE HIM!"<<endl;
		}
		else
		{
			cout<<"CHAT WITH HER!"<<endl;
		}
	}
	return 0;
}
