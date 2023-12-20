#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while(cin>>s)
	{
	int minn=INT_MAX;
		for(int j=1;j<=s.size();j++)
		{
			int flag=1;
			if(s.size()%j!=0)
			 continue;
			string cp(s,0,j);
			for(int k=0;k<s.size()-j+1;k+=j)
			{
				string cut(s,k,j);
				if(cut!=cp)
				 flag=0;
			}
			if(flag)
			 if(j<minn) minn=j;
		}
		cout<<minn<<endl;
	}
	return 0;
}
