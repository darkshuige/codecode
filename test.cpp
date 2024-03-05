#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
using namespace std;
const int N = 2e5 + 10, mod = 998244353, inf = 2e18;
typedef pair<int, int> PII;
int n, m, res = 1;
struct node{
    int l, r;
    int maxn, remaxn;
    int mnum, rnum;
}tr[4 * N];
int p[N];
void pushup(node& root, node& left, node& right){
    if(left.maxn == right.maxn){
        root.maxn = left.maxn;
        root.mnum = left.mnum + right.mnum;
        if(left.remaxn == right.remaxn){
            root.remaxn = left.remaxn;
            root.rnum = left.rnum + right.rnum;
        }
        else if(left.remaxn > right.remaxn){
            root.remaxn = left.remaxn;
            root.rnum = left.rnum;
        }
        else if(left.remaxn < right.remaxn){
            root.remaxn = right.remaxn;
            root.rnum = right.rnum;
        }
    }
    else if(left.maxn > right.maxn){
        root.maxn = left.maxn;
        root.mnum = left.mnum;
        if(left.remaxn == right.maxn){
            root.remaxn = left.remaxn;
            root.rnum = left.rnum + right.mnum;
        }
        else if(left.remaxn > right.maxn){
            root.remaxn = left.remaxn;
            root.rnum = left.rnum;
        }
        else if(left.remaxn < right.maxn){
            root.remaxn = right.maxn;
            root.rnum = right.mnum;
        }
    }
    else if(left.maxn < right.maxn){
        root.maxn = right.maxn;
        root.mnum = right.mnum;
        if(left.maxn == right.remaxn){
            root.remaxn = left.maxn;
            root.rnum = left.mnum + right.rnum;
        }
        else if(left.maxn > right.remaxn){
            root.remaxn = left.maxn;
            root.rnum = left.mnum;
        }
        else if(left.maxn < right.remaxn){
            root.remaxn = right.remaxn;
            root.rnum = right.rnum;
        }
    }
}
void build(int u, int l, int r){
    if(l == r) tr[u] = {l, r, p[l], 0, 1, 0};
    else{
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
    }
}
void modify(int u, int pos, int x){
    if(tr[u].l == tr[u].r && tr[u].l == pos){
        tr[u].maxn = x;
    }
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(pos <= mid) modify(u << 1, pos, x);
        else modify(u << 1 | 1, pos, x);
        pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
    }
}
node query(int u, int l, int r){
    if(tr[u].l >= l && tr[u].r <= r){
        return tr[u];
    }
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        node a, b;
        int f1 = 0, f2 = 0;
        if(l <= mid){
            f1++;
            a = query(u << 1, l, r);
        }
        if(r > mid){
            f2++;
            b = query(u << 1 | 1, l , r);
        }
        if(f1 && f2){
            node c = {l, r};
            pushup(c, a, b);
            return c;
        }
        else{
            if(f1) return a;
            if(f2) return b;
        }
    }
}
signed main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> p[i];
    build(1, 1, n);
    for(int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            modify(1, b, c);
        }
        else{
            cout << query(1, b, c).rnum << endl;
        }
    }
	return 0;
}
