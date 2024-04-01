#include<iostream>
using namespace std;
int main()
{
	int n;
	string a[5];
	cin>>n;
	for(int i=0;i<5;i++)
	 cin>>a[i];
	for(int j=0;j<4*n;j++)
	{
		if(a[3][j]=='*')
		{
			if(j%4==1)
			 cout<<"1";
			else if(j%4==2)
			 cout<<"3";
			else 
			 cout<<"2";
		}
	}
}
