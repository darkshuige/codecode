#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int M=1000000000;
const int maxn=300;
map<char,char>mp;
signed main()
{
	jiasu;
	mp['4']='a';
	mp['6']='b';
	mp['c']='c';
	mp['d']='d';
	mp['3']='e';
	mp['f']='f';
	mp['9']='g';
	mp['h']='h';
	mp['i']='i';
	mp['j']='j';
	mp['k']='k';
	mp['1']='l';
	mp['m']='m';
	mp['n']='n';
	mp['0']='o';
	mp['p']='p';
	mp['q']='q';
	mp['r']='r';
	mp['5']='s';
	mp['7']='t';
	mp['u']='u';
	mp['v']='v';
	mp['w']='w';
	mp['x']='x';
	mp['y']='y';
	mp['2']='z';
	string s;
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if(mp.count(s[i]))
		 cout<<mp[s[i]];
		else
		 cout<<s[i];
	}
	cout<<endl;
    return 0;
} 
