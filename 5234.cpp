#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<string,double>a,pair<string,double>b)
{
	return a.second>b.second;
}
int main()
{
	pair<string,double>a[5];
	for(int i=0;i<5;i++)
	{
		string s;
		double a1,a2,a3,a4,a5;
		cin>>s>>a1>>a2>>a3>>a4>>a5;
		a[i].first=s;
		a[i].second=(a1+a2+a3+a4+a5)/5.0;
	}
	sort(a,a+5,cmp);
	for(int i=0;i<5;i++)
	{
		cout<<"Name:"<<a[i].first<<endl;
		cout<<"Æ½¾ù³É¼¨£º";
		if(a[i].second==(int)a[i].second)
		 cout<<(int)a[i].second<<endl;
		else
		 printf("%.1f\n",a[i].second);
	}
	return 0;
} 
