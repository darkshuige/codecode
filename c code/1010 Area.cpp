#include<bits/stdc++.h>
#define int long long
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
using namespace std;
const int maxn=1010;
pair<double,double>a[maxn];
//pair<double,double>第一个元素存储坐标点的x坐标，第二个元素存储坐标点的y坐标
// 计算矢量(pk-pi)与矢量(pj-pi)的叉乘
int direction(pair<double,double>pi,pair<double,double>pj,pair<double,double>pk)
{
    return (pk.first-pi.first)*(pj.second-pi.second)-(pj.first-pi.first)*(pk.second-pi.second);
}
//在矢量(pk-pi)与矢量(pj-pi)的叉乘为0的基础上，判断点pk是否在线段pipj上，如果在的话返回true，否则返回false;
bool on_segment(pair<double,double>pi,pair<double,double>pj,pair<double,double>pk)
{
    return min(pi.first,pj.first)<=pk.first&&pk.first<=max(pi.first,pj.first)&&min(pi.second,pj.second)<=pk.second&&pk.second<=max(pi.second,pj.second);
}
//判断线段p1p2是否与线段p3p4相交,相交返回true,不相交返回false;
bool f(pair<double,double>p1,pair<double,double>p2,pair<double,double>p3,pair<double,double>p4)
{
    int d1=direction(p3,p4,p1);
    int d2=direction(p3,p4,p2);
    int d3=direction(p1,p2,p3);
    int d4=direction(p1,p2,p4);
    if(((d1>0 && d2<0)||(d1<0 && d2>0))&&((d3>0 && d4<0)||(d3<0 && d4>0)))
     return true;
    else if(d1==0 && on_segment(p3,p4,p1))
     return true;
    else if(d2==0 && on_segment(p3,p4,p2))
     return true;
    else if(d3==0 && on_segment(p1,p2,p3))
     return true;
    else if(d4==0 && on_segment(p1,p2,p4))
     return true;
    else
     return false;
}
signed main()
{
	int n;
	int case1=0;
	while(cin>>n)
	{
		if(n==0)
		 break;
		double sum=0;
		int flag=1;
		cin>>a[1].first>>a[1].second;
		for(int i=2;i<=n;i++)
		{
			cin>>a[i].first>>a[i].second;
			if(flag==1)
			{
				sum+=(0.5)*(a[i-1].second+a[i].second)*(a[i].first-a[i-1].first);
				for(int j=2;j<=i-2;j++)
				{
					if(f(a[j-1],a[j],a[i-1],a[i])==1)
					{
						flag=0;
						break;
					}
				}	
			}
		}
		sum+=(0.5)*(a[1].second+a[n].second)*(a[1].first-a[n].first);
		if(flag==1)
		{
			for(int j=3;j<=n-1;j++)
			{
				if(f(a[j-1],a[j],a[n],a[1])==1)
				{
					flag=0;
					break;
				}
			}	
		}
		case1++;
		if(case1!=1) cout<<endl;
		cout<<"Figure "<<case1<<": ";
		if(flag==0 || n<3)
		 cout<<"Impossible"<<endl;
		else if(flag==1)
		 cout<<fixed<<setprecision(2)<<fabs(sum)<<endl;
	}
	return 0;
} 

