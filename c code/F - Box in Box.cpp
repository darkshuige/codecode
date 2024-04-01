#include<bits/stdc++.h>
using namespace std;
struct box
{
	int k[3];
}a[200005];
int cmp1(int a,int b)
{
	return a>b;
}
int cmp2(box a,box b)
{
	if(a.k[0]!=b.k[0])
	 return a.k[0]>b.k[0];
	else
	 if(a.k[1]!=b.k[1])
	  return a.k[1]>b.k[1];
	 else
	  return a.k[2]>b.k[2];
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int b[3];
		cin>>b[0]>>b[1]>>b[2];
		sort(b,b+3,cmp1);
		a[i].k[0]=b[0];
		a[i].k[1]=b[1];
		a[i].k[2]=b[2];
	}	
	sort(a,a+n,cmp2);
	if(a[0].k[0]>a[n-1].k[0] && a[0].k[1]>a[n-1].k[1] && a[0].k[2]>a[n-1].k[2])
	 cout<<"Yes"<<endl;
	else
	 cout<<"No"<<endl;
	return 0;	
} 

