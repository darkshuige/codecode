#include<bits/stdc++.h>
using namespace std;
int cmp(const int a,const int b)
{
	return a>b;
}
int main()
{
	int n;
	int cc=1;
	while(cin>>n)
	{
		int count=0;
		for(int i=0;i<n;i++)
		{
			int a[27]={0};
			string s;
			cin>>s;
			if(s.size()==1)
			{
				continue;
			}
			for(int j=0;j<s.size();j++)
			{
				a[s[j]-'a']++;
			}
			sort(a,a+26,cmp);
			int op=0;
			while(a[op]) op++;
			int flag=1;
			for(int k=0;k<op-1;k++)
			{
				for(int l=k+1;l<op;l++)
				{
					if(a[l]==a[k])
					 flag=0;
				}
			}
			if(flag)
			 count++;
		}
		printf("Case %d: %d\n",cc++,count);
	}
	return 0;	
}
