#include<bits/stdc++.h>
using namespace std;
struct person
{
	char name[100];
	int count,sum;
};
int cmp(person a,person b)
{
	if(a.count!=b.count)
	 return a.count>b.count;
	else
	 if(a.sum!=b.sum)
	  return a.sum<b.sum;
	   else
	    return strcmp(a.name,b.name)<0;
}
int main()
{
	int n,m,p;
	while(cin>>n>>m>>p)
	{
		person a[10010];
		memset(a,0,sizeof a);
		for(int i=0;i<p;i++)
		{
			string s;
			cin>>a[i].name;
			for(int j=0;j<n;j++)
			{
				cin>>s;
				int k=0,fs=0;
				int pos=s.find("(");
				if(pos!=string::npos)
				{
					a[i].count++;
					for(int l=0;l<pos;l++)
					 k=k*10+(s[l]-48);
					for(int l=pos+1;l<s.size()-1;l++)
					 fs=fs*10+(s[l]-48);
					a[i].sum+=k;
					a[i].sum+=fs*m;
				}
				else if(s[0]!='-' && s[0]!='0')
				{
					for(int l=0;l<s.size();l++)
					 k=k*10+(s[l]-48);
					a[i].sum+=k;
					a[i].count++;
				}
			}
		}
		sort(a,a+p,cmp);
		for(int i=0;i<p;i++)
		 printf("%-10s %2d %4d\n",a[i].name,a[i].count,a[i].sum);	
	}
	
	return 0;
} 
