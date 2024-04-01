#include<bits/stdc++.h>
using namespace std;
bool a[100000005]={0};
void init()
{
	a[1]=1;
	a[2]=1;
	a[3]=0;
	for(int i=4;i<=1005;i++)
	{
		if(a[i-1]==0)
		 a[i]=1;
		if(a[i-2]==0)
		 a[i]=1;
		if(i>=9)
		{
			if(i==9)
			 a[i]=1;
			else
			 if(a[i-9]==0)
			  a[i]=1;
		}
		if(i>=20)
		{
			if(i==20)
			 a[i]=1;
			else
			 if(a[i-20]==0)
			  a[i]=1;
		}
		if(i>=24)
		{
			if(i==24)
			 a[i]=1;
			else
			 if(a[i-24]==0)
			  a[i]=1;
		}
	}
}
int main()
{
	init();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		if(x>100)
		{
            x %= 50;
            x+=25;
        }
        if(a[x])
         cout<<"GuaGua shi 1!CeCe shi 0!"<<endl;
        else
         cout<<"CeCe shi 1!GuaGua shi 0!"<<endl;
	}
    return 0;
}
