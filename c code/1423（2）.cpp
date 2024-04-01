#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	while(cin>>str)
	{
		transform(str.begin(),str.end(),str.begin(),::tolower);
		for(int i=0;i<str.size();i++)
		{
			if(str[i]=='a'||str[i]=='o'||str[i]=='y'||str[i]=='e'||str[i]=='u'||str[i]=='i')
			{
				str.erase(i,1);
				i--;
			}
		}
		for(int i=0;i<str.size();i++)
		{
			cout<<".";
			cout<<str[i];
		}
		cout<<endl;
	}
	return 0;
}
