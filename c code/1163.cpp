#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k;
	while(cin>>k)
	{
		int flag=0;
		for(int i=k+1;i<=2*k;i++)
		{
			if(i*k%(i-k)==0)
			{
				flag=1;
				printf("1/%d=1/%d+1/%d\n",k,i*k/(i-k),i);
			}
		}
		if(flag==0)
		 cout<<-1<<endl;
	}
	return 0;
}
