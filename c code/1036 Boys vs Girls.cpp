#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
struct person
{
	string name,id;
	int score;
};
vector<person>a,b;
int cmp1(person a,person b)
{
	return a.score<b.score;
}
int cmp2(person a,person b)
{
	return a.score>b.score;
}
signed main()
{
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		string a1,a2,a3;
		int bb;
		cin>>a1>>a2>>a3>>bb;
		if(a2=="M")
		 a.push_back({a1,a3,bb});
		else
		 b.push_back({a1,a3,bb});
	}
	sort(a.begin(),a.end(),cmp1);
	sort(b.begin(),b.end(),cmp2);
	if(b.size()==0)
	 cout<<"Absent"<<endl;
	else
	 cout<<b[0].name<<" "<<b[0].id<<endl;
	if(a.size()==0)
	 cout<<"Absent"<<endl;
	else
	 cout<<a[0].name<<" "<<a[0].id<<endl;
	if(a.size()==0 || b.size()==0)
	 cout<<"NA"<<endl;
	else
	 cout<<b[0].score-a[0].score<<endl;
	return 0;
} 
