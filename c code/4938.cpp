#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[210];
	while(gets(a))
	{
		sort(a,a+strlen(a));
		cout<<a<<endl;
	}
	return 0;
}
