#include<bits/stdc++.h>
using namespace std;
string manacherString(string str)
{
	int len=str.size()*2+1;
	char res[len];
	int index=0;
	for(int i=0;i<len;i++)
	{
		res[i]=(i&1)==0?'#':str[index++];
	}
	return res;
}
int manacher(string s)
{
	string str=manacherString(s);
	int pArr[str.size()];
	int C=-1;
	int R=-1;
	int maxn=1;
	for(int i=0;i<str.size();i++)
	{
		pArr[i]=R>i?min(pArr[2*C-i],R-i):1;
		while(i+pArr[i]<str.size()&&i-pArr[i]>-1)
		{
			if(str[i+pArr[i]]==str[i-pArr[i]])
			pArr[i]++;
			else
			break;
		}
		if(i+pArr[i]>R)
		{
			R=i+pArr[i];
			C=i;
		}
		maxn=max(maxn,pArr[i]);
	}
	return maxn-1;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string str;
		cin>>str;
		printf("%d\n",manacher(str));
	}
	return 0;
 } 
