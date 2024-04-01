#include<bits/stdc++.h>
using namespace std;
int f(char a)
{
	if(a=='0') return 0;
	if(a=='1') return 1;
	if(a=='2') return 2;
	if(a=='3') return 3;
	if(a=='4') return 4;
	if(a=='5') return 5;
	if(a=='6') return 6;
	if(a=='7') return 7;
	if(a=='8') return 8;
	if(a=='9') return 9;
	if(a=='A') return 10;
	if(a=='B') return 11;
	if(a=='C') return 12;
	if(a=='D') return 13;
	if(a=='E') return 14;
	if(a=='F') return 15;
}
int main()
{
	string s;
	while(cin>>s)
	{
		long long sum=0;
		for(int i=1;i<=s.size();i++)
		{
			sum+=f(s[i-1])*pow(16,s.size()-i);
		}
		cout<<sum<<endl;
	}
	return 0;
}
