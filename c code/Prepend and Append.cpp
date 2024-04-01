#include<iostream>
#include<string>
using namespace std;
int main()
{
	int t,i,n,l,r,flag;
	string s;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n;
		cin>>s;
		l=0;
		r=n-1;
		flag=1;
		while(flag && l<r)
		{
			flag=0;
			if((s[l]=='0' && s[r]=='1') || (s[l]=='1' && s[r]=='0'))
			{
				n=n-2;
				flag=1;
				l++;
				r--;
			}
		}
		cout<<n<<endl;
	}
	return 0;
}
