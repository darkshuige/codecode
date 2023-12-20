	#include<bits/stdc++.h>
	using namespace std;
	int main()
	{
		string s;
		cin>>s;
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int l,r;
			string a,b;
			cin>>l>>r>>a>>b;
			string cut(s,l-1,r-l+1);
			s.erase(l-1,r-l+1);
			int l1=a.size();
			int len=a.size()+b.size();
			int flag=0;
			int j;
			for(j=0;j<s.size();j++)
			{
				if(j+len>s.size())
				 break;
				string cp1(s,j,a.size());
				string cp2(s,j+a.size(),b.size());
				if(cp1==a && cp2==b)
				{
					flag=1;
					break;
				}
			}
			if(flag)
			 s.insert(j+l1,cut);
			else
			 s.insert(s.size(),cut);
		}
		cout<<s<<endl;
		return 0;
	} 
