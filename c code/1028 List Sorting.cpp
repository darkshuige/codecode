#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
const int st=8*3600;
const int ed=21*3600;
map<int,char>mp;
struct node
{
	string name1,name2;
	int score;
}a[maxn];
int cmp1(node a,node b)
{
	return a.name1<b.name1;
}
int cmp2(node a,node b)
{
	if(a.name2!=b.name2)
	 return a.name2<b.name2;
	else
	 return a.name1<b.name1;
}
int cmp3(node a,node b)
{
	if(a.score!=b.score)
	 return a.score<b.score;
	else
	 return a.name1<b.name1;
}
signed main()
{
	int n,c; cin>>n>>c;
	for(int i=0;i<n;i++)
	 cin>>a[i].name1>>a[i].name2>>a[i].score;
	if(c==1)
	 sort(a,a+n,cmp1);
	else if(c==2)
	 sort(a,a+n,cmp2);
	else
	 sort(a,a+n,cmp3);
	for(int i=0;i<n;i++)
	 cout<<a[i].name1<<" "<<a[i].name2<<" "<<a[i].score<<endl;
	return 0;
} 