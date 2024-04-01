#include<bits/stdc++.h>
using namespace std;	
const int N=1e5+5;
int a[N],cnt[18];
int main()
{
	int n,m;
	while(~scanf("%d",&n))
	{
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i++)
		{
			char k[3];
			scanf("%s",k);
			if(k[0]>='3'&&k[0]<='9') a[i]=k[0]-'0';
			else if(k[0]=='J') a[i]=11;
			else if(k[0]=='Q') a[i]=12;
			else if(k[0]=='K') a[i]=13;
			else if(k[0]=='A') a[i]=14;
			else if(k[0]=='2') a[i]=15;
			else a[i]=10;
			cnt[a[i]]++;
		}
		sort(a+1,a+n+1);
		scanf("%d",&m);
		while(m--)
		{
			int x,y;
			char k[3];
			scanf("%d %s",&x,k);
			if(k[0]>='3'&&k[0]<='9') y=k[0]-'0';
			else if(k[0]=='J') y=11;
			else if(k[0]=='Q') y=12;
			else if(k[0]=='K') y=13;
			else if(k[0]=='A') y=14;
			else if(k[0]=='2') y=15;
			else y=10;
			if(x>cnt[y]) 
			{
				printf("-1\n");
				continue;
			}
			int l=1,r=n,pos;
			while(l<=r)
			{
				int mid=l+r>>1;
				if(y<=a[mid]) 
				 pos=mid,r=mid-1;
				else 
				 l=mid+1;
			}
			printf("%d\n",pos+x-1);
		}
	}
	return 0;
}
