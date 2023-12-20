#include<bits/stdc++.h>
using namespace std;
const int maxn=1000100;
int Next[maxn];
void getNext(string str)//约等于自己和自己比 
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
	string s1;
	string s2;
	while(cin>>s1>>s2)
	{
		memset(Next,0,sizeof(Next));
	    cout<<KMP(s1,s2)<<endl;
	}
	return 0;
 }
