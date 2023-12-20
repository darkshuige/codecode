#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		char a[2005];
		cin>>a;
		int pos1=0,pos2=n-1;
		while(((a[pos1]=='0' && a[pos2]=='1') || (a[pos1]=='1' && a[pos2]=='0')) && pos1<pos2)
		{
			pos1++;
			pos2--;
		}
		cout<<pos2-pos1+1<<endl;
	}
    return 0;
}

