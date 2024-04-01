#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	getchar();
	for(int i=0;i<n;i++)
	{
		string s;
		getline(cin,s);
		int j=0;
		while(s[j]==' ')
		 j++;
		int count=1;
		for(j;j<s.size()-1;j++)
		{
			if(s[j]==' ' && s[j+1]!=' ')
			{
				count++;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
