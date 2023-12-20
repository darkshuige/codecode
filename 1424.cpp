#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
    while(cin>>n)
    {
    	int count=0;
    	map<int,int>sb;
    	for(int i=0;i<n;i++)
    	{
    		int a;
    		cin>>a;
    		if(a==4)
    		{
    			count++;
			}
			else if(a==1)
			{
				if(sb[3]>0)
				{
					sb[3]--;
				}
				else
				{
					sb[1]++;
					count++;
				}
			}
			else if(a==2)
			{
				if(sb[2]>0)
				{
					sb[2]--;
				}
				else
				{
					sb[2]++;
					count++;
				}
			}
			else if(a==3)
			{
				if(sb[1]>0)
				{
					sb[1]--;
				}
				else
				{
					sb[3]++;
					count++;
				}
			}
		}
		while(sb[1]>=2 && sb[2]>=1)
		{
			sb[1]-=2;
			sb[2]--;
			count-=2;
		}
		while(sb[1]>=1 && sb[2]>=1)
		{
			sb[1]--;
			sb[2]--;
			count--;
		}
		while(sb[1]>=4)
		{
			sb[1]-=4;
			count-=3;
		}
		while(sb[1]>=3)
		{
			sb[1]-=3;
			count-=2;
		}
		while(sb[1]>=2)
		{
			sb[1]-=2;
			count--;
		}
		cout<<count<<endl;
	}
	return 0;
}
