#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
    	int l,n;
    	cin>>l>>n;
    	int flag=0;
    	int f=1;
    	int sum=0;
    	int pos=0;
    	int a[100005]={0};
    	for(int j=0;j<n;j++)
    	{
    		int op,x;
    		cin>>op;
    		if(op==0)
    		{
    			cin>>x;
    			a[x]++;
    			flag++;
			}
			else if(op==1)
			{
				int fff=0;
				if(flag==0)
				{
					continue;
				}
				else
				{
					int k=0;
					while(pos-k>=0 && pos+k<=n)
					{
						if(a[pos+k]>0 || a[pos-k]>0)
						{
							fff=1;
							if(a[pos+k]>0 && a[pos-k]>0)
							{
								if(f==1)
								 pos+=k;
								else if(f==-1)
								 pos-=k;
							}
							else if(a[pos+k]>0 && a[pos-k]==0)
							{
								f=1;
								pos+=k;
							}
							else if(a[pos+k]==0 && a[pos-k]>0)
							{
								f=-1;
								pos-=k;
							}
							sum+=k;
							a[pos]--;
							break;
						}
						k++;
					}
					if(fff==0)
					{
						if(pos+k<=n)
						{
							while(pos+k<=n)
							{
								if(a[pos+k]>0)
								{
									sum+=k;
									pos+=k;
									a[pos]--;
									f=1;
									break;
								}
								k++;
							}	
						}
						else
						{
							while(pos-k>=0)
							{
								if(a[pos-k]>0)
								{
									sum+=k;
									pos-=k;
									a[pos]--;
									f=-1;
									break;
								}
								k++;
							}	
						}	
					}
					flag--;
				}
			}
		}
		printf("Case %d: %d\n",i,sum);
	}
    return 0;
}
