#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int i,count=0;
		for(i=n-1;i>=0;i--)
		{
			count++;
			cout<<"a";
			int j;
			for(j=1;j<=i;j++)
			 cout<<" ";
			char l='a';
			for(j=0;j<count;j++)
			{
				cout<<l;
				l++;
			}
			cout<<endl;
		}	
		cout<<endl;
	}
	
	return 0;
}
