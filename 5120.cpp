#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		getchar();
		set<string>st;
		string a[10005];
		int k=0;
		for(int i=0;i<n;i++)
		{
			string s;
			getline(cin,s);
			if(st.count(s)==0)
			{
				a[k++]=s;
				st.insert(s);
			}
		}
		cout<<st.size()<<endl;
		for(int i=0;i<k;i++)
		 cout<<a[i]<<endl;	
	}
	
	return 0;
} 
