#include<bits/stdc++.h>
using namespace std;
const int maxn=1000100;
int Next[maxn];
void getNext(string str)
{
	Next[0]=-1;
	Next[1]=0;
	int i=2;
	int j=0;
	while(i<str.size())
	{
		if(str[i-1]==str[j])
		 Next[i++]=++j;
		else if(j>0)
		 j=Next[j];
		else
		 Next[i++]=0;
	}
}
int KMP(string str1,string str2)
{
	int i1=0,i2=0;
	getNext(str2);
	int res=0;
	while(i1<str1.size())
	{
		if(str1[i1]==str2[i2])
		{
			i1++;
			i2++;
		}
		else if(i2==0)
		 i1++;
		else
		 i2=Next[i2];
		if(i2==str2.size())
		{
			i2=0;
			res++;
		}
	}
	return res;
}
int main()
{
	int t;
	scanf("%d",&t);
	int n;
	while(t--)
	{
		string a,b;
		scanf("%d",&n);
		cin>>b;
		string s="";
		for(int i=0;i<n;i++)
			s=s+"1";
		a=b+s+b;
		if(KMP(a,b)==2)
		{
			cout<<s<<endl;continue;
		}
		s="";
		for(int i=0;i<n;i++)
			s=s+"0";
		a=b+s+b;
		if(KMP(a,b)==2)
		{
			cout<<s<<endl;continue;
		}
		cout<<-1<<endl;
	}
	return 0;
}
