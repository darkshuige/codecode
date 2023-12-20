#include<bits/stdc++.h>
using namespace std;
char op[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j'};
int main()
{
	string a1,b1,t;
	
	while(cin>>a1>>b1)
	{
		if(a1.size()<b1.size())//a长度永远大于等于b 
		{
			t=a1;a1=b1;b1=t;
		}
		int a[105]={0},b[105]={0},c[105]={0};
		int i;
		for(i=0;i<a1.size();i++)
		{
			if(a1[i]<='z' && a1[i]>='a')
			{
				a[i]=(int)(a1[i])-97+10;
			}
			else
			 a[i]=a1[i]-'0';
		}
		for(i=0;i<b1.size();i++)
		{
			if(b1[i]<='z' && b1[i]>='a')
			{
				b[i]=(int)(b1[i])-97+10;
			}
			else
			 b[i]=b1[i]-'0';
		}
		int k=0,l;
		for(i=b1.size()-1,l=a1.size()-1;i>=0;i--,l--,k++)
		{
			c[k]=b[i]+a[l];
		}
		while(l>=0)
		{
			c[k]=a[l];
			k++,l--;
		}
		for(i=0;i<k-1;i++)
		{
			c[i+1]+=c[i]/20;
			c[i]%=20;
		}
		if(c[i]>=20)
		{
			c[i+1]+=c[i]/20;
			c[i]%=20;
			k++;
		}
		for(i=k-1;i>=0;i--)
		{
			cout<<op[c[i]];
		}
		cout<<endl;
	}
	return 0;
}
