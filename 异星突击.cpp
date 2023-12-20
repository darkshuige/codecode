#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int N = 1e5 + 5, M = 1e5 * 32 + 5, INF = 0x3f3f3f3f;
int n, hp, idx = 1;
int cnt[M], tr[M][2]; // 计数每个节点的数字数量 和子节点编号
// 插入
void insert(int x, int num) //x是要插入的数  num是个数（1 or -1） 
{
    int p = 1; // 从根节点开始
    for (int i = 30; i >= 0; i--) 
	{
        int d = (x >> i) & 1;  //右移i位 除以2的i次  &1 看那一位是0还是1 
        if (!tr[p][d]) 
		 tr[p][d] = ++idx;
        p = tr[p][d];
        
        cnt[p] += num;  // 当前节点上的数字数量+1 或者-1 
    }
}

int find(int x, int h)
{
    int p = 1, res = 0; // 从根节点开始搜索
    for (int i = 30; i >= 0; i--) //i从大到小，从左往右找 
	{
        int d = (x >> i) & 1;   // x这一位的值
        int dh = (h >> i) & 1;  // h这一位的值
        if (!dh) 
		{              // h当前位为0,则选择异或后值为1的所有数都能使结果大于h
            res += cnt[tr[p][d ^ 1]];   // 异或后值为1的所有数数量
            p = tr[p][d];       // 继续查找当前位异或后为0的数
        }
		else 
		{                // h当前位为1,想要异或后大于h只能选择查找当前值异或后值为1的数
            p = tr[p][d ^ 1];
        }
    }
    return res; // 返回结果
}

int main ()
{
    // 输入输出
    cin >> n >> hp;
    for (int i = 0; i < n; i++) 
	{
        int op, x, h;
        cin >> op;
        if (op == 0) 
		{
            cin >> x;
            insert(x, 1);
        } 
		else if (op == 1) 
		{
            cin >> x;
            insert(x, -1);
        } 
		else if (op == 2) 
		{
            cin >> x >> h;
            int res = find(x, h);
            cout << res << endl;
            if (res == 0) 
			 hp--;
        }
    }
    cout << hp << endl;
    return 0;
}
