#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int f(int num, int target) 
{
    list<int> people;
    for (int i = 0; i < num; ++i) 
     people.push_back(i);
    auto it = people.begin();
    while (num > 1) 
	{
        for (int count = 1; count < target; ++count) 
		{
            ++it;
            if (it == people.end()) 
             it = people.begin();
        }
        it = people.erase(it);
        if (it == people.end()) 
         it = people.begin();
        --num;
    }
    return *people.begin();
}
signed main() 
{
    int num, target;
    cin >> num >> target;
    cout<< f(num, target) << endl;
    return 0;
}
