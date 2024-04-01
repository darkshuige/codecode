#include<bits/stdc++.h>
using namespace std;
char a[100005];
int main()
{
	while(cin>>a)
	{
		int l=0,r=strlen(a)-1;
		int cnt=0;
		while(l<=r)
		{
			if(a[l]!=a[r])
			 cnt++;
			l++;
			r--;
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
