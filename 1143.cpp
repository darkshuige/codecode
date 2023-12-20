#include<iostream>
#include<algorithm>
using namespace std;
int cmp(const int a,const int b)
{
	return a<b;
}
int main()
{
	int n,m;
	while(cin>>m>>n)
	{
		int a[100010]={0};
		int i;
		for(i=1;i<=n;i++)
		 cin>>a[i];
		sort(a+1,a+n+1,cmp);
		for(i=1;i<=n;i++)
		{
			if(a[i]<m)
			 m+=2;
			else
			{
				m++;
				n--;
				i--;
			}
		}
		cout<<m<<endl;
	}
	return 0;
}
