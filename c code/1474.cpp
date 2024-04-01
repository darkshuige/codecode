#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
	int n,w,s;
	while(cin>>n>>w>>s)
	{
		int a[70]={0};
		for(int i=1;i<=n;i++)
		 a[i]=i;
		int k=1;
		while(n)
		{
			if(w==n+1)
			 w=1;
			if(k==s)
			{
				cout<<a[w]<<endl;
				for(int i=w;i<n;i++)
				  a[i]=a[i+1];	
				n--;
				k=0;
				w--;
			}
			k++;
			w++;
		}
	}
	return 0;
}
