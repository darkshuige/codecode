#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n0,n1,n;
	cin>>n0>>n1>>n;
	int flag=0;
	int minn=INT_MAX;
	int pos1=-1,pos2=-1;
	for(int i=1;i<n;i++)
	{
		if(n0/i==(double)(n0)/(double)(i) && n1/(n-i)==(double)(n1)/(double)(n-i))
		{
			if(abs((n0/i)-(n1/(n-i)))<minn)
			{
				minn=abs((n0/i)-(n1/(n-i)));
				pos1=i;
				pos2=n-i;
				flag=1;
			}
		}
	}
	if(flag)
	{
		cout<<pos1<<" "<<pos2<<endl;
	}
	else
	{
		cout<<"No Solution"<<endl;
	}
	return 0;
} 
