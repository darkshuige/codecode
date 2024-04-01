#include<bits/stdc++.h>
using namespace std;
int f(int a)
{
	int sum=1;
	for(int i=1;i<=a;i++)
	 sum*=i;
	return sum;
}
int main()
{
	int a,b,c;
	cin>>a>>b;
	c=a+b;
	cout<<f(c)<<endl;
	return 0;
} 
