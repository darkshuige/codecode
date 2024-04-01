#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	vector<int>v;
	cin>>n>>k;
	for(int i=0;i<=n;i++)
	 v.push_back(i);
	int pos=k;
	int cnt=0;
	while(v.size()>1)
	{
		while(pos>v.size()-1)
		 pos-=(v.size()-1);
		if(cnt!=0)
		 cout<<" ";
		cnt++;
		cout<<v[pos];
		v.erase(v.begin()+pos);
		if(v.size()==1)
		 break;
		pos--;
		pos+=k;
	}
	return 0;
}
