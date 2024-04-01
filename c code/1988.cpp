#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a,b,c;
	while(cin>>a>>b>>c)
	{
		int time1,time2;
		time1=((b[0]-48)*10+(b[1]-48))*60+(b[2]-48)*10+(b[3]-48);
		time2=((c[0]-48)*10+(c[1]-48))*60+(c[2]-48)*10+(c[3]-48);
		cout<<a<<" "<<"to"<<" "<<"Kunming: ";
		printf("%02d:%02d\n",(time2-time1)/60,(time2-time1)%60);
	}
	return 0;
}
