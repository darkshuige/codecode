#include<iostream>
using namespace std;
int main()
{
	int a,i;
	char b;
	cin>>a;
	for(i=0;i<a;i++)
	{
		cin>>b;
		if(b=='c' || b=='o' || b=='d' || b=='e' || b=='f' || b=='o' || b=='r' || b=='c' ||
		b=='e' || b=='s')
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
} 
