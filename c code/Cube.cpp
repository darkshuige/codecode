#include<bits/stdc++.h>
using namespace std;
struct point
{
	int x;
	int y;
	int z;
}a[8];
long long jlpf(struct point p1,struct point p2)
{
	return pow((p1.x-p2.x),2)+pow((p1.y-p2.y),2)+pow((p1.z-p2.z),2);
}
int main()
{
	set<long long>s;
	int t,i;
	cin>>t;
	for(i=0;i<t;i++)
	{
		s.clear();
		int j;
		for(j=0;j<=7;j++)
		 cin>>a[j].x>>a[j].y>>a[j].z;
		int k;
		for(j=0;j<=6;j++)
		{
			for(k=j+1;k<=7;k++)
			{
				s.insert(jlpf(a[j],a[k]));
			}
		}
		long long sum1=0,sum2=0;
		int cnt=1;
		set<long long>::iterator it;
		for(it=s.begin(); it!=s.end();it++) 
        {
        	cnt++;
        	if(cnt!=3)
        	sum1+=*it;
        	else
        	sum2+=*it;
		}
		if(s.size()==3 && sum1==sum2)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
