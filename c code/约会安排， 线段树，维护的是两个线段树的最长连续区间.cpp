#include <bits/stdc++.h>
#define rep(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
const int N = 1E5 + 10;
struct node {
    int l, r;
    int fmax[2], lmax[2], rmax[2]; //0为基友  1为女神
    int lazy[2];
}t[N << 2];
void pushdown(int id, node& op, int lazy) { //id用于区分基友和女神
    op.fmax[0] = (op.r - op.l + 1) * lazy;
    op.lmax[0] = op.rmax[0] = op.fmax[0];
    op.lazy[0] = lazy;
    
    if (id == 1) {
        op.fmax[1] = op.lmax[1] = op.rmax[1] = op.fmax[0];
        op.lazy[1] = op.lazy[0];
    }
}
void pushdown(int x) {
    if (t[x].lazy[1] != -1) pushdown(1, t[x << 1], t[x].lazy[1]), pushdown(1, t[x << 1 | 1], t[x].lazy[1]);
    if (t[x].lazy[0] != -1) pushdown(0, t[x << 1], t[x].lazy[0]), pushdown(0, t[x << 1 | 1], t[x].lazy[0]);
    t[x].lazy[0] = t[x].lazy[1] = -1;
}

void pushup(int x) {
    node& p = t[x], &l = t[x << 1], &r = t[x << 1 | 1];
    for (int i = 0; i < 2; ++i) {
        p.fmax[i] = max(max(l.fmax[i], r.fmax[i]), l.rmax[i] + r.lmax[i]);
        p.lmax[i] = l.lmax[i] + (l.lmax[i] == l.r - l.l + 1 ? r.lmax[i] : 0);
        p.rmax[i] = r.rmax[i] + (r.rmax[i] == r.r - r.l + 1 ? l.rmax[i] : 0);
    }
}

void build(int l, int r, int x = 1) {
    t[x] = { l, r, 1, 1, 1, 1, 1, 1, -1, -1 };
    if (l == r) return;
    int mid = l + r >> 1;
    build(l, mid, x << 1), build(mid + 1, r, x << 1 | 1);
    pushup(x);
}

void modify(int l, int r, int id, int c, int x = 1) {
    if (l <= t[x].l && r >= t[x].r) {
        pushdown(id, t[x], c);
        return;
    }
    pushdown(x);
    int mid = t[x].l + t[x].r >> 1;
    if (l <= mid) modify(l, r, id, c, x << 1);
    if (r > mid) modify(l, r, id, c, x << 1 | 1);
    pushup(x);
}

int findleft(int l, int r, int id, int c, int x = 1) { //返回至少有c连续空闲时间的区间左端点
    if (t[x].l == t[x].r) return t[x].l;
    pushdown(x);
    if (t[x << 1].fmax[id] >= c) return findleft(l, r, id, c, x << 1);
    if (t[x << 1].rmax[id] + t[x << 1 | 1].lmax[id] >= c) return t[x << 1].r - t[x << 1].rmax[id] + 1;
    return findleft(l, r, id, c, x << 1 | 1);
}
int main()
{
    int T; cin >> T;
        rep(CASE, T) {
            printf("Case %d:\n", CASE);
            int n, m; scanf("%d %d", &n, &m);
            build(1, n);
            while (m--) {
                char s[10]; scanf("%s", s);
                if (*s == 'S') {
                    int l, r; scanf("%d %d", &l, &r);
                    modify(l, r, 1, 1);
                    printf("I am the hope of chinese chengxuyuan!!\n");
                }
                else {
                    int c; scanf("%d", &c);
                    
                    if (*s == 'N') {
                        int id = -1;
                        if (t[1].fmax[0] >= c) id = 0;
                        else if (t[1].fmax[1] >= c) id = 1;
                        
                        if (id != -1) {
                            int l = findleft(1, n, id, c);
                            modify(l, l + c - 1, 1, 0);
                            printf("%d,don't put my gezi\n", l);
                        }
                        else printf("wait for me\n");
                    }
                    else if (*s == 'D') {
                        if (t[1].fmax[0] >= c) {
                            int l = findleft(1, n, 0, c);
                            modify(l, l + c - 1, 0, 0);
                            printf("%d,let's fly\n", l);
                        }
                        else printf("fly with yourself\n");
                    }
                }
            }
        }
    return 0;
}
