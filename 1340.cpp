#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    int cc=1;
    while(cin>>n>>m)
    {
    	if(n==0 && m==0)
    	 break;
    	int a[1005]={0};
    	for(int i=0;i<m;i++)
    	{
    		int k;
    		cin>>k;
    		a[k]++;
		}
		int win=0;
		int dp=0;
		for(int i=n*m;i>0;i--)
		{
			if(a[i])
			{
				if(dp==0)
				{
					win++;		
				}		
				else
				{
					dp--;
				}
			}		
			else
			{
				dp++;
			}
		}	
		cout << "Case " << cc << ": " << win << endl;	
		cc++;
	}
	return 0;
}
