#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[10]={0};
	int cnt1=0,cnt2=0;
	for(int i=0;i<n;i++)
	{
		int op;
		cin>>op;
		if(op==0)
		{
			if(cnt1>0)
			{
				cnt2++;
				cnt1--;
			}
		}
		else if(a[5]==0 && a[2]==0)
		{
			if(op==5)
			{
				a[5]++;	
			}
		}
		else if(a[5]!=0 && a[2]==0)
		{
			if(op==5)
			{
				a[5]++;	
			}
			else if(op==2)
			{
				a[2]++;
			}
		}
		while(a[5]>0 && a[2]>0)
		{
			a[5]--;
			a[2]--;
			cnt1++;		
		}		
	}
	cout<<cnt2<<endl;
    return 0;
}
