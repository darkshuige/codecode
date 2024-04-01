#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		getchar();
		for(int i=0;i<n;i++)
		{
			string s;
			getline(cin,s);
			int k=0;
			while(s[k]==' ')
			 k++;
			cout<<(char)toupper(s[k]);
			for(k;k<s.size()-1;k++)
			 if(s[k]==' ' && s[k+1]!=' ')
		 	  cout<<(char)toupper(s[k+1]);
		 	cout<<endl;
		}
	}
	return 0;
}
