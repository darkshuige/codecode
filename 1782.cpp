#include<bits/stdc++.h>
using namespace std;
int main()
{
	int h1,h2,s1,s2;
	while(scanf("%d:%d %d:%d",&h1,&s1,&h2,&s2)!=EOF)
	{
		int t1,t2;
		t1=h1*60+s1;
		t2=h2*60+s2;
		cout<<(t2-t1)/10<<endl;
	}
	return 0;
}
