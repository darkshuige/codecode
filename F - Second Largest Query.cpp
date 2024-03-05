<<<<<<< HEAD
#include <iostream>
using namespace std;

int overlap(int x1, int y1, int z1, int x2, int y2, int z2) {
    int dx = min(x1 + 7, x2 + 7) - max(x1, x2);
    int dy = min(y1 + 7, y2 + 7) - max(y1, y2);
    int dz = min(z1 + 7, z2 + 7) - max(z1, z2);
    if (dx <= 0 || dy <= 0 || dz <= 0) return 0;
    return dx * dy * dz;
}


bool check(int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int V1, int V2, int V3) {
    int V2_ = overlap(x1, y1, z1, x2, y2, z2) + overlap(x1, y1, z1, x3, y3, z3) + overlap(x2, y2, z2, x3, y3, z3);
    int V3_ = overlap(x1, y1, z1, x2, y2, z2);
    return V1 == 3 * 294 - 2 * V2_ - V3_ && V2 == V2_ && V3 == V3_;
}


int main() {
    int V1, V2, V3;
    cin >> V1 >> V2 >> V3;
    for (int x1 = 0; x1 <= 7; x1++) {
        for (int y1 = 0; y1 <= 7; y1++) {
            for (int z1 = 0; z1 <= 7; z1++) {
                for (int x2 = 0; x2 <= 7; x2++) {
                    for (int y2 = 0; y2 <= 7; y2++) {
                        for (int z2 = 0; z2 <= 7; z2++) {
                            for (int x3 = 0; x3 <= 7; x3++) {
                                for (int y3 = 0; y3 <= 7; y3++) {
                                    for (int z3 = 0; z3 <= 7; z3++) {
                                        if (check(x1, y1, z1, x2, y2, z2, x3, y3, z3, V1, V2, V3)) {
                                            cout << "Yes" << endl;
                                            cout << x1 << " " << y1 << " " << z1 << " " << x2 << " " << y2 << " " << z2 << " " << x3 << " " << y3 << " " << z3 << endl;
                                            return 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "No" << endl;
}
=======
#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=200005;
int mod;
struct node
{
	int l,r;
	int maxn,remaxn;
	int mnum,rnum;
}tr[maxn*4];
int w[maxn];
void pushup(node &root,node &left,node &right)
{
	if(left.maxn == right.maxn)
	{
        root.maxn = left.maxn;
        root.mnum = left.mnum + right.mnum;
        if(left.remaxn == right.remaxn)
		{
            root.remaxn = left.remaxn;
            root.rnum = left.rnum + right.rnum;
        }
        else if(left.remaxn > right.remaxn)
		{
            root.remaxn = left.remaxn;
            root.rnum = left.rnum;
        }
        else if(left.remaxn < right.remaxn)
		{
            root.remaxn = right.remaxn;
            root.rnum = right.rnum;
        }
    }
    else if(left.maxn > right.maxn)
	{
        root.maxn = left.maxn;
        root.mnum = left.mnum;
        if(left.remaxn == right.maxn)
		{
            root.remaxn = left.remaxn;
            root.rnum = left.rnum + right.mnum;
        }
        else if(left.remaxn > right.maxn)
		{
            root.remaxn = left.remaxn;
            root.rnum = left.rnum;
        }
        else if(left.remaxn < right.maxn)
		{
            root.remaxn = right.maxn;
            root.rnum = right.mnum;
        }
    }
    else if(left.maxn < right.maxn)
	{
        root.maxn = right.maxn;
        root.mnum = right.mnum;
        if(left.maxn == right.remaxn)
		{
            root.remaxn = left.maxn;
            root.rnum = left.mnum + right.rnum;
        }
        else if(left.maxn > right.remaxn)
		{
            root.remaxn = left.maxn;
            root.rnum = left.mnum;
        }
        else if(left.maxn < right.remaxn)
		{
            root.remaxn = right.remaxn;
            root.rnum = right.rnum;
        }
    }
}
void build(int p,int l,int r)
{
	tr[p]={l,r,w[l],0,1,0};
	if(l==r) return ;
	int mid=l+r>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	pushup(tr[p],tr[lc],tr[rc]);
}
void update(int p,int pos,int x)
{
	if(tr[p].l==tr[p].r && tr[p].l==pos)
	 tr[p].maxn=x;
	else
	{
		int mid=tr[p].l+tr[p].r>>1;
		if(pos<=mid) update(lc,pos,x);
		else update(rc,pos,x);
		pushup(tr[p],tr[lc],tr[rc]);
	}	
}
node query(int p,int l,int r)
{
	if(tr[p].l>=l && tr[p].r<=r) return tr[p];
	else
	{
		int mid=tr[p].l+tr[p].r>>1;
		node a,b;
		int f1=0,f2=0;
		if(l<=mid)
		{
			f1++;
			a=query(lc,l,r);
		}
		if(r>mid)
		{
			f2++;
			b=query(rc,l,r);
		}
		if(f1 && f2)
		{
			node c={l,r};
			pushup(c,a,b);
			return c;
		}
		else
		{
			if(f1) return a;
			if(f2) return b;
		}
	}
}
signed main()
{
	jiasu;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 cin>>w[i];
	build(1,1,n);
	for(int i=0;i<m;i++)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int b,c;
			cin>>b>>c;
			update(1,b,c);
		}
		else
		{
			int l,r;
			cin>>l>>r;
			cout<<query(1,l,r).rnum<<endl;
		}
	}
	return 0;
} 
>>>>>>> 96e2c5c1b47a7f7970217f6f1233ff118d1cd711
