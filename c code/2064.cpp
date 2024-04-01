#include<bits/stdc++.h>
using namespace std;
int toint(string s)
{
	int sum=0;
	for(int i=0;i<s.size();i++)
	 sum=sum*10+(s[i]-48);
	return sum;
}
int main()
{
    int n;
    while(cin>>n)
    {
    	int a[100005]={0};
    	getchar();
    	string s;
    	for(int i=0;i<n;i++)
    	{
    		getline(cin,s);
    		int k=0;
    		while(s[k]==' ')
    		 k++;
    		s.erase(0,k);
    		k=0;
    		while(k!=s.size())
    		{
    			if(s[k]==' ')
    			{
    				string cut(s,0,k);
    				int x=toint(cut);
    				a[x]++;
    				s.erase(0,k+1);
    				k=0;
				}
				else
				 k++;
			}
			int x=toint(s);
			a[x]++;
		}
		int i=0;
		int pos1=-1,pos2=-1;
		while(a[i]==0)
		 i++;
		while(pos1==-1 || pos2==-1)
		{
			if(a[i]==0)
			 pos1=i;
			if(a[i]==2)
			 pos2=i;
			i++;
		}
		cout<<pos1<<" "<<pos2<<endl;
	}
    return 0;
}
