#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=n;i>=1;i--)
	{
		int count=n-i+1;
		int jia=n;
		for(int j=0;j<i;j++)
		{
			printf("%4d",count);
			count+=jia;
			jia--;
		}
		cout<<endl;
	}
	return 0;
}
