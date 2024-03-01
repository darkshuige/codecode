#include<bits/stdc++.h>
//#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=2000;
const int MAXN = maxn;
const int MAXM = maxn;
struct Node 
{ 
    int l, r; 
    bool val; 
    Node *left, *right;
    Node(int l, int r): l(l), r(r), val(false), left(NULL), right(NULL) {} 
};
Node* build(int l, int r) 
{
    Node* root = new Node(l, r);
    if (l == r) return root; 
    int m = (l + r) / 2; 
    root->left = build(l, m); 
    root->right = build(m + 1, r); 
    return root; 
}
void update(Node* root, int x, char c) 
{ 
    if (root->l == root->r) 
	{ 
        root->val = (c == '*'); 
        return;
    }
    int m = (root->l + root->r) / 2; 
    if (x <= m) update(root->left, x, c); 
    else update(root->right, x, c); 
    root->val = root->left->val && root->right->val; 
}
bool query(Node* root, int l, int r) 
{ 
    if (l <= root->l && root->r <= r) return root->val; 
    int m = (root->l + root->r) / 2; 
    bool res = true; 
    if (l <= m) res = res && query(root->left, l, r); 
    if (r > m) res = res && query(root->right, l, r); 
    return res; 
}
struct Tree 
{ 
    int l, r; 
    Node* root; 
    Tree *left, *right; 
    Tree(int l, int r): l(l), r(r), root(NULL), left(NULL), right(NULL) {}
};
Tree* build(int l, int r, int m) 
{ 
    Tree* root = new Tree(l, r); 
    root->root = build(1, m);
    if (l == r) return root; 
    int mid = (l + r) / 2; 
    root->left = build(l, mid, m);
    root->right = build(mid + 1, r, m); 
    return root; 
}
void update(Tree* root, int x, int y, char c) 
{ 
    update(root->root, y, c); 
    if (root->l == root->r) return; 
    int mid = (root->l + root->r) / 2; 
    if (x <= mid) update(root->left, x, y, c); 
    else update(root->right, x, y, c); 
}
bool query(Tree* root, int x1, int y1, int x2, int y2) 
{ 
    if (x1 <= root->l && root->r <= x2) return query(root->root, y1, y2); 
    int mid = (root->l + root->r) / 2; 
    bool res = true; 
    if (x1 <= mid) res = res && query(root->left, x1, y1, x2, y2); 
    if (x2 > mid) res = res && query(root->right, x1, y1, x2, y2); 
    return res; 
}
char a[maxn][maxn];
int count(int n, int m,Tree* root) 
{
	int count = 0;
	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= m; j++) 
		{
			if (a[i][j] == '*')
			{
				int len = 1;
				while (i + len <= n && j - len > 0 && j + len <= m && a[i + len][j - len] == '*' && a[i + len][j + len] == '*' && query(root,i+len,j-len,i+len,j+len)) 
				{
					count++;
					len++;
				}
			}
		}
	}
	return count;
}
signed main()
{
	jiasu;
    int n,m;
    cin>>n>>m;
    Tree* root = build(1, n, m); 
    int sum=0;
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=m;j++)
    	{
    		cin>>a[i][j];
    		update(root,i,j,a[i][j]); 
    		if(a[i][j]=='*')
    		 sum++;
		}
	}
	cout<<count(n,m,root)+sum<<endl;
    return 0;
}