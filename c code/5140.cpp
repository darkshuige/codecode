#include<bits/stdc++.h>
using namespace std;
int f(string a)
{
	int ans=0;
	ans=(a[0]-48)*100+(a[1]-48)*10+(a[2]-48);
	return ans; 
}
int main()
{
	string a,b,c;
	while(cin>>a>>b>>c)
	{
		int a1,b1,c1;
		a1=f(a),b1=f(b),c1=f(c);
		if(a1+b1==c1)
		 cout<<"YES!"<<endl;
		else
		 cout<<"NO!"<<endl; 
	}
	return 0;
}
