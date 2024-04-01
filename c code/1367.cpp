#include<bits/stdc++.h>
using namespace std;
int k[1000005]={0};
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(k,0,sizeof k);
		set<int>sb;
		for(int i=0;i<n;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			if(a==1)
			{
				sb.insert(b);
				k[b]=1;
			}
			else if(a==2)
			{
				if(k[b]==1)
				{
					sb.erase(b);
					k[b]=0;
				}
			}
			else
			{
				if(k[b]==1)
				{
					int cc=1;
					set<int>::iterator it;
					for(it=sb.begin();it!=sb.end();it++,cc++)
					{
						if(*it==b)
						 break;
					}
					printf("%d\n",cc);
				}
				else
				{
					printf("sorry\n");
				}
			}
		}
	}
	return 0;
} 
