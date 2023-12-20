#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int N = 1e5 + 5, M = 1e5 * 32 + 5, INF = 0x3f3f3f3f;
int n, hp, idx = 1;
int cnt[M], tr[M][2]; // ����ÿ���ڵ���������� ���ӽڵ���
// ����
void insert(int x, int num) //x��Ҫ�������  num�Ǹ�����1 or -1�� 
{
    int p = 1; // �Ӹ��ڵ㿪ʼ
    for (int i = 30; i >= 0; i--) 
	{
        int d = (x >> i) & 1;  //����iλ ����2��i��  &1 ����һλ��0����1 
        if (!tr[p][d]) 
		 tr[p][d] = ++idx;
        p = tr[p][d];
        
        cnt[p] += num;  // ��ǰ�ڵ��ϵ���������+1 ����-1 
    }
}

int find(int x, int h)
{
    int p = 1, res = 0; // �Ӹ��ڵ㿪ʼ����
    for (int i = 30; i >= 0; i--) //i�Ӵ�С������������ 
	{
        int d = (x >> i) & 1;   // x��һλ��ֵ
        int dh = (h >> i) & 1;  // h��һλ��ֵ
        if (!dh) 
		{              // h��ǰλΪ0,��ѡ������ֵΪ1������������ʹ�������h
            res += cnt[tr[p][d ^ 1]];   // ����ֵΪ1������������
            p = tr[p][d];       // �������ҵ�ǰλ����Ϊ0����
        }
		else 
		{                // h��ǰλΪ1,��Ҫ�������hֻ��ѡ����ҵ�ǰֵ����ֵΪ1����
            p = tr[p][d ^ 1];
        }
    }
    return res; // ���ؽ��
}

int main ()
{
    // �������
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
