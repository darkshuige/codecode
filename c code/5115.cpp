#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int flag=0;
	int i;
	for(i=n/10;i>=0;i--)
	{
		if((n-i*10)%3==0)
		{
			flag=1;
			break;
		}
	}
	if(flag)
	 cout<<i*3+(n-i*10)/3<<endl;
	else
	 cout<<"orz"<<endl;
	return 0;
} 
