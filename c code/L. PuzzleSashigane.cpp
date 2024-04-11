#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=10005;
int xx[5],yy[5];
struct node
{
	int x,y,a1,b1;
}a[maxn];
signed main()
{
	jiasu;
	int n,sx,sy;
	cin>>n>>sx>>sy;
	xx[1]=1,xx[2]=1,xx[3]=n,xx[4]=n;//左上 右上 左下 右下
	yy[1]=1,yy[2]=n,yy[3]=1,yy[4]=n;
	cout<<"Yes"<<endl;
	int cnt=0;
	int pos=-1;
	while(1)
	{
		int ma=LLONG_MIN;
		for(int i=1;i<=4;i++)
		{
			if(abs(xx[i]-sx)+abs(yy[i]-sy)>ma)
			{
				ma=abs(xx[i]-sx)+abs(yy[i]-sy);
				pos=i;
			}
		}
		if(ma==0) break;
		int shangxia,zuoyou;
		if(pos==1)
		{
			shangxia=xx[4]-xx[1];
			zuoyou=yy[2]-yy[1];
			a[cnt++]={xx[pos],yy[pos],shangxia,zuoyou};
			xx[1]++; yy[1]++;
			xx[2]++;
			yy[3]++;
		}
		if(pos==2)
		{
			shangxia=xx[4]-xx[2];
			zuoyou=-(yy[2]-yy[1]);
			a[cnt++]={xx[pos],yy[pos],shangxia,zuoyou};
			xx[2]++; yy[2]--;
			yy[4]--;
			xx[1]++;
		}
		if(pos==3)
		{
			shangxia=-(xx[3]-xx[1]);
			zuoyou=yy[4]-yy[3];
			a[cnt++]={xx[pos],yy[pos],shangxia,zuoyou};
			xx[3]--; yy[3]++;
			yy[1]++;
			xx[4]--;
		}
		if(pos==4)
		{
			shangxia=-(xx[4]-xx[2]);
			zuoyou=-(yy[4]-yy[3]);
			a[cnt++]={xx[pos],yy[pos],shangxia,zuoyou};
			xx[4]--; yy[4]--;
			xx[3]--;
			yy[2]--;
		}
	}
	cout<<cnt<<endl;
	for(int i=0;i<cnt;i++)
	 cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].a1<<" "<<a[i].b1<<endl;
	return 0;
}