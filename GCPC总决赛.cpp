#include<bits/stdc++.h>
using namespace std;
int jiecheng(int n)
{
	int i=1,sum=1;
	for(i=1;i<=n;i++)
	{
		sum*=i;
	}
	return sum;
}
int main()
{
    int n,count=0;
    cin>>n;
    int a[20],b[20];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    sort(b,b+n);
    int x=0,y=0,z=0;
    int flag1=0,flag2=0;
    do
    {
     flag1=0;flag2=0;
     for(int i=0;i<n;i++)
     {
	      if(a[i]>b[i])
	      flag1++;
	      else if(a[i]<b[i])
	      flag2++;
     }
	  if(flag1>flag2)
	  x++;
	  else if(flag1<flag2)
	  y++;
	  else
	  z++;
	  count++;
 	}
 	while(next_permutation(b,b+n) || count<jiecheng(n));
  	 cout<<x<<" "<<y<<" "<<z<<endl;
    return 0;
}
