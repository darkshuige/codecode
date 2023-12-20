#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i;
	int a[20]={0};
	for(i=0;i<10;i++)
	{
		cin>>a[i];
	}
	int count=0;
	sort(a,a+10);
	int x;
	cin>>x;
	x+=30;
	for(i=0;i<10;i++)
	{
		if(x>=a[i])
		 count++;
	}
	cout<<count<<endl;
	return 0;
}
