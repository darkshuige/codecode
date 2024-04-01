#include<iostream>
#include<string>
using namespace std;
int main()
{
	int t,i,n,j,sum,k,flag;
	int a[26]={0};
	cin>>t;
	string s;
	for(i=0;i<t;i++)
	{
		for(k=0;k<26;k++)
		 a[k]=0;
		flag=0;
		sum=0;
		cin>>n;
		cin>>s;
		for(j=0;j<n;j++)
		{
			if(a[s[j]-'a']!=0 && flag==0)
			{
				for(k=0;k<26;k++)
				 a[k]=0;
				flag=1;
			}
			a[s[j]-'a']++;
			if(a[s[j]-'a']==1)
			{
				sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
