#include<bits/stdc++.h>
using namespace std;
struct sb
{
	int l,r;
};
int cmp(sb a,sb b)
{
	if(a.l!=b.l)
	 return a.l<b.l;
	else
	 return a.r<b.r;
}
int main()
{
	int l,m;
	while(cin>>l>>m)
	{
		if(l==0 && m==0)
		 break;
		sb a[105];
		for(int i=0;i<m;i++)
		 cin>>a[i].l>>a[i].r;
		sort(a,a+m,cmp);
		int l1,l2,r1,r2,ans=0;
		l1=a[0].l,r1=a[0].r;
		ans+=l1-0;
		for(int i=1;i<m;i++)
		{
			l2=a[i].l,r2=a[i].r;
			if(l2<=r1 && r2>r1)
			 r1=r2;
			else if(l2>r1)
			{
				ans+=l2-(r1+1);
				l1=l2;
				r1=r2;	
			}	
		}	
		ans+=l-r1;
		cout<<ans<<endl;
	}
	return 0;
} 
