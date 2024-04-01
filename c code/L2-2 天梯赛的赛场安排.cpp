#include<bits/stdc++.h>
using namespace std;
struct xinxi
{
	int xh;
	string mz;
	int rs;
	int gs;
}a[5005];
int cmp1(struct xinxi d1,struct xinxi d2)
{
	if(d1.rs!=d2.rs)
	{
		return d1.rs>d2.rs;	
	}
	else
	{
		return d1.xh<d2.xh;
	}
}
int cmp2(const int a,const int b)
{
	return a<b;
}
int cmp3(struct xinxi d1,struct xinxi d2)
{
	return d1.xh<d2.xh;
}
int main()
{
	int kjs[5005];
	int k=0;
	int n,c;
	cin>>n>>c;
	int n1=n;
	int count=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].mz>>a[i].rs;
		a[i].xh=i;
	}
	while(n)
	{
		sort(a,a+n1,cmp1);
		if(a[0].rs>c)
		{
			int cs=a[0].rs/c;
			a[0].rs-=c*cs;
			a[0].gs+=cs;
			count+=cs;
		}
		else if(a[0].rs==c)
		{
			a[0].rs=0;
			a[0].gs++;
			count++;
			n--;
		}
		else if(a[0].rs<c)
		{
			int flag=0;
			sort(kjs,kjs+k,cmp2);
			for(int j=0;j<k;j++)
			{
				if(kjs[j]>=a[0].rs)
				{
					kjs[j]-=a[0].rs;
					a[0].gs++;
					a[0].rs=0;
					n--;
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				kjs[k++]=c-a[0].rs;
				count++;
				a[0].rs=0;
				a[0].gs++;
				n--;
			}
		}
	}
	sort(a,a+n1,cmp3);
	for(int i=0;i<n1;i++)
	{
		cout<<a[i].mz<<" "<<a[i].gs<<endl;
	}
	cout<<count<<endl;
	return 0;
} 
