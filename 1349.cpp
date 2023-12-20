#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a,b;
	cin>>a>>b;
	int h1,h2,s1,s2;
	if(a.size()==3)
	{
		h1=a[0]-'0';
		s1=(a[1]-'0')*10+(a[2]-'0');
	}
	else
	{
		h1=(a[0]-'0')*10+(a[1]-'0');
		s1=(a[2]-'0')*10+(a[3]-'0');
	}
	if(b.size()==3)
	{
		h2=b[0]-'0';
		s2=(b[1]-'0')*10+(b[2]-'0');
	}
	else
	{
		h2=(b[0]-'0')*10+(b[1]-'0');
		s2=(b[2]-'0')*10+(b[3]-'0');
	}
	int time1,time2;
	time1=s1+h1*60;
	time2=s2+h2*60;
	int time=time2-time1;
	printf("The train journey time is %d hrs %d mins.\n",time/60,time%60);
	return 0;
}
