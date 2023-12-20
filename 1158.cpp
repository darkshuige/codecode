#include<iostream>
using namespace std;
int main()
{
	int d,n;
	while(cin>>d>>n)
	{
		int count=0;
		int op=1;
		while(count<d-1)
		{	
			if(n%2==1)
			{
				n=n/2+1;
				op*=2;
				count++;
			}
			else if(n%2==0)
			{
				n=n/2;
				op=op*2+1;
				count++;
			}	
		}
		cout<<op<<endl;		
	}
	
	return 0;
}
