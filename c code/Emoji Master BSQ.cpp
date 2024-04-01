#include<iostream>
#include<cstring>
using namespace std;
int n,m;
string s[110], s1[110], s2[110];
int main()
{
    cin>> n >> m;
    for(int i=0;i<n;i++)
    {
        cin>>s1[i]>>s2[i];
    }
    for(int i=0;i<m;i++)
        cin>> s[i];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(s[i]==s1[j])
             s[i]=s2[j];
        }
    }
    for(int i=0;i<m;i++)
    {
    	if(i!=0)
    	{
    		cout<<" ";
		}
    	cout<<s[i];	
	}
     
    return 0;
}
