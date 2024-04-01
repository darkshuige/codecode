#include<iostream>
#include<algorithm>
using namespace std;
struct fs
{
	double cgl;
	int fs;
}a[100005];
int cmp(const int a,const int b)
{
	return a>b;
}

int main()
{
	int dsdf[100005]={0};
	int n,m,q,i,f1,f2,pm,j;
	int point=-1;
	int fs=-1;
	double jl=-1;
	cin>>n>>m>>q;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].cgl>>a[i].fs;
	}
	for(i=1;i<=m;i++)
	{
		cin>>dsdf[i];
	}
	sort(dsdf+1,dsdf+m+1,cmp);
	for(i=0;i<q;i++)
	{
		cin>>f1>>pm;
		f2=dsdf[pm];
		for(j=1;j<=n;j++)
		{
			if(a[j].fs+f1>=f2 && a[j].fs>=fs)
			{
				if(a[j].fs>fs)
				{
					jl=a[j].cgl;
					fs=a[j].fs;
					point=j;
				}
				else if(a[j].fs==fs)
				{
					if(a[j].cgl>jl)
					{
						jl=a[j].cgl;
						fs=a[j].fs;
						point=j;
					}
				}
			}
		}
		if(point!=-1 && fs!=-1 && jl!=-1)
		{
			cout<<point<<endl;
		}
		else
		{
			cout<<"-1"<<endl;
		}
		point=-1;
		fs=-1;
		jl=-1;
	}
	return 0;
}
