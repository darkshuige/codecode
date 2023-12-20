#include<bits/stdc++.h>
using namespace std;
int res=0;
int a[20];
int s;
int act(int pos,int sum)
{
	if(sum+a[pos]<s)
	{
		act(pos+1,sum+a[pos]);
		act(pos+1,sum);
	}
	else if(sum+a[pos]==s)
	{
		
	}
	else if(sum+a[pos]>s)
	{
		act(pos+1,sum);
	}
}
int main()
{
	while(cin>>s)
	{
		int n;
		cin>>n;
		res=0;
		memset(a,0,sizeof a);
		for(int i=0;i<n;i++)
		 cin>>a[i];
		act(0,0);
		printf("Sums of %d:\n",s);
		if(res==0)
		 cout<<"NONE";
		cout<<endl;
	}
	return 0;
} 
