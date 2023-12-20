#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a+b==c)
		{
			cout<<"Tu Dou"<<endl;
		}
		else if(a*b==c)
		{
			cout<<"Lv Yan"<<endl;
		}
		else
		{
			cout<<"zhe du shi sha ya!"<<endl;
		}
	}
	return 0;
} 
