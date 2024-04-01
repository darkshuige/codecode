#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		set<int>sb;
		int flag=1;
		string s;
		for(int i=0;i<n;i++)
		{
			cin>>s;
			int pos1=s.find('G'),pos2=s.find('S');
			if(pos1>pos2)
			{
				flag=0;
				break;
			}
			sb.insert(pos2-pos1);
		}
		if(flag==0)
		 cout<<-1<<endl;
		else
		 cout<<sb.size()<<endl;
	}
	return 0;
} 
