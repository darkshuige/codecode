#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {
       int l=s.size();
       if(s[l-1]=='0')
       {
    		cout<<l<<" "<<0<<endl;
       }
       else
       {
			cout<<0<<" "<<l<<endl;
       }
    }
  return 0;
}
