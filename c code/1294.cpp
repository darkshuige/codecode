#include<bits/stdc++.h> 
using namespace std;
int main() 
{
	int t;
	cin>>t;
    for(int j=0;j<t;j++)
    {
    	string s;
    	cin>>s;
    	int len=s.size();
    	for(int i=0;i<len;i++)
    	{
    		if(i%2==0)
    		 cout<<(char)((((s[i]-48)+9)%10)+48);
		}
		for(int i=0;i<len;i++)
    	{
    		if(i%2==1)
    		 cout<<char((((s[i]-48)+9)%10)+48);
		}
		cout<<endl;
	}
    return 0;
}
