#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,q;
	while(cin>>n>>q)
	{
		char a[200],b[200];
		scanf("%s",a);
		strcpy(b,a);
		for(int i=0;i<q;i++)
		{
			strcpy(a,b);
			int ans[10]={0};
			int l,r;
			cin>>l>>r;
			l--,r--;
			int pos=-1,d=1;
			for(int j=l;j>=l && j<=r;j+=d)
			{
				if(a[j]<='9' && a[j]>='0')
				{
					ans[a[j]-48]++;
					a[j]--;
					pos=n;
				}
				else if(a[j]=='<' || a[j]=='>')
				{
					if(a[pos]=='<' || a[pos]=='>')
                     a[pos]='.';
					pos=j;
					if(a[j]=='<')
                     d=-1;
                    else if(a[j]=='>')
                     d=1;					 
				}
			}
			for(int j=0;j<10;j++)
			{
				if(j!=0)
				 cout<<" ";
				cout<<ans[j];
			}
			cout<<endl;
		}
	}
	return 0;
} 
