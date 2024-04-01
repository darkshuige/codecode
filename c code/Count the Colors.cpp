/**************
*Author:MySakure
*Time:2019-05-22
*Source:ZOJ1610
*Theme:Ïß¶ÎÊ÷
State:Accept
***************/

#include<iostream>
#include<set>
#define lc p<<1
#define rc p<<1|1
using namespace std;

const int maxn=8020;
struct Node
{
    int l,r,c;
}tr[maxn<<4];
int n,x,y,c;
int wall[maxn],num[maxn];
void pushup(int p)
{
	if(tr[lc].c==tr[rc].c)
	{
		tr[p].c=tr[lc].c;
	}
	else
	 tr[p].c=-1;
}
void Build(int root,int l,int r)
{
    tr[root]={l,r,-2};
    if(l==r)
	{
        tr[root].c=-1;
        return;
    }
    int mid=(l+r)>>1;
    Build(root<<1,l,mid);
    Build(root<<1|1,mid+1,r);
    pushup(root);
}
void PushDown(int root)
{
    if(tr[root].c==-2 || tr[root].c==-1) return;
    tr[root<<1].c=tr[root<<1|1].c=tr[root].c;
    pushup(root);
}
void Update(int root,int l,int r,int c)
{
    if(tr[root].l>=l && tr[root].r<=r)
	{
        tr[root].c=c;
        return;
    }
    PushDown(root);
    int mid=(tr[root].l+tr[root].r)>>1;
    if(r<=mid)Update(root<<1,l,r,c);
    else if(l>mid)Update(root<<1|1,l,r,c);
    else
	{
        Update(root<<1,l,mid,c);
        Update(root<<1|1,mid+1,r,c);
    }
    pushup(root);
}
int quare(int root,int inx)
{
    if(tr[root].c!=-1&&tr[root].l<=inx&&tr[root].r>=inx)
    {
        return tr[root].c;
    }
    if(tr[root].l==inx&&tr[root].r==inx)
	{
        return tr[root].c;
    }
    int mid=(tr[root].l+tr[root].r)>>1;
    return inx<=mid?quare(root<<1,inx):quare(root<<1|1,inx);
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    while(cin>>n)
	{
        Build(1,0,8000);
        //cerr<<"build success"<<endl;
        for(int i=0;i<=8010;++i)
        {
            wall[i]=-1;
            num[i]=0;
        }
        int mx=0;
        for(int i=1;i<=n;++i)
        {
            cin>>x>>y>>c;
            Update(1,x,y-1,c);
            mx=max(mx,y);
            //cerr<<"ok"<<endl;
        }
        //cerr<<"emmmm"<<endl;
        for(int i=0;i<=mx;++i)
            {
                wall[i]=quare(1,i);
                //cerr<<"color "<<i<<" "<<wall[i]<<endl;
            }
        //cerr<<"hello "<<endl;
        for(int i=0;i<=mx;++i){
            if(wall[i]!=wall[i+1]&&wall[i]!=-1)
                num[wall[i]]++;
        }
        for(int i=0;i<=8000;++i)
            if(num[i])cout<<i<<" "<<num[i]<<endl;
        cout<<endl;
    }
    return 0;
}
