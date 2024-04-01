#include<bits/stdc++.h>
using namespace std;
int s[100005];
int a1[100005];
int b1[100005]; 
string a,b;
int n1,n2;
int main()
{
	while(cin>>a>>b)
	{
		n1=a.size();
		n2=b.size();
		memset(s,0,sizeof(s));
		memset(a1,0,sizeof(a1));
		memset(b1,0,sizeof(b1));
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		for(int i=0;i<n1;i++)
		{
			a1[i]=a[i]-48;
		}
		for(int i=0;i<n2;i++)
		{
			b1[i]=b[i]-48;
		}
		for(int i=0;i<n1;i++)
		{
			for(int j=0;j<n2;j++)
			{
				s[i+j]+=a1[i]*b1[j];
			}
		}
		for(int i=0;i<n1+n2;i++)
		{
			s[i+1]+=s[i]/10;
			s[i]%=10;
		}
		int i=n1+n2;
		for(;i>=1;i--)
		 if(s[i]>0)
		  break;
		for(i;i>=0;i--)
		{
			cout<<s[i];
		}
		cout<<endl;
	}	
	return 0;
}
