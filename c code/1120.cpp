#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int k;
	while(cin>>k)
	{
		k=abs(k);
		int i=1;
		int sum=0;
		while(1)
		{
			sum+=i;
			i++;
			if(sum==k)
			{
				cout<<i-1<<endl;	
				break;
			}
			 
			else
			{
				if((sum-k)%2==0 && sum>k)
				{
					cout<<i-1<<endl;
					break;
				}
			}
		}
	}
	return 0;
}
