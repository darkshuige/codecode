#include<bits/stdc++.h>
using namespace std;
int c[10000010]={0};
void act(char a,string &b)
{
	if(a=='0') b+="0000";
	if(a=='1') b+="0001";
	if(a=='2') b+="0010";
	if(a=='3') b+="0011";
	if(a=='4') b+="0100";
	if(a=='5') b+="0101";
	if(a=='6') b+="0110";
	if(a=='7') b+="0111";
	if(a=='8') b+="1000";
	if(a=='9') b+="1001";
	if(a=='A') b+="1010";
	if(a=='B') b+="1011";
	if(a=='C') b+="1100";
	if(a=='D') b+="1101";
	if(a=='E') b+="1110";
	if(a=='F') b+="1111";
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		memset(c,0,sizeof c);
		string a,b;
		b="";
		cin>>a;
		for(int j=0;j<a.size();j++)
		{
			act(a[j],b);
		}
		if(b.size()%3==1)
		 b="00"+b;
		else if(b.size()%3==2)
		 b="0"+b;
		int k=0;
		for(int j=0;j<b.size()-2;j+=3)
		{
			c[k++]=((b[j]-'0')*4)+((b[j+1]-'0')*2)+(b[j+2]-'0');
		}
		int flag=0;
		for(int j=0;j<k;j++)
		{
			if(flag==0)
			{
				if(c[j]==0)
				 continue;
				else
				{
					flag=1;
					cout<<c[j];
				}
			}
			else
			 cout<<c[j];	
		}
		cout<<endl;
	}
	return 0;
}
