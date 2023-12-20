#include <iostream>
#include <string>
using namespace std;
const int maxNum = 1005;
int shift[maxNum];
int Sunday(const string& T, const string& P)
{
	int n = T.length();
	int m = P.length();
	for (int i = 0; i < maxNum; i++)
	{
		shift[i] = m + 1;
	}
	for (int i = 0; i < m; i++)
	{
		shift[P[i]] = m - i;
	}
	int s = 0;
	int j;
	while (s <= n - m)
	{
		j = 0;
		while (T[s + j] == P[j])
		{
			j++;
			if (j >= m) {
				return s;
			}
		}
		s += shift[T[s + m]];
	}
	return -1;
}
int main() 
{
	string T, P;
	while (true)
	{
		getline(cin, T);
		getline(cin, P);
		int res = Sunday(T, P);
		if (res == -1)
		{
			cout << "主串和模式串不匹配。" << endl;
		}
		else
		{
			cout << "模式串在主串的位置为：" << res+1 << endl;
		}
	}
	return 0;
}


