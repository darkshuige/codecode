#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			int t;
			cin>>t;
			string s="";
			int flag=0;
			for(int j=0;j<t;j++)
			{
				string cp;
				cin>>cp;
				if(flag==0)
				{
					if(cp[0]!='0' && cp.size())
					{
						flag=1;	
						s+=cp;
					}
					while(flag==0 && cp[0]=='0' && cp.size())
					{
						cp.erase(0,1);
						if(cp[0]!='0' && cp.size())
						{
							flag=1;	
							s+=cp;
						}
					}
				}
				else
				{
					s+=cp;	
				}
			}
			if(s=="")
			 cout<<0<<endl;
			 else
			cout<<s<<endl;
		}	
	}
	
	return 0;
}
