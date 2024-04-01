#include<iostream>
#include<string>
using namespace std;
int main()
{
	int a,b,c,flag=0,i=0,count=0;
	cin>>a>>b;
	c=a+b;
	string d=to_string(a+b);
	if(d[0]=='-')
	{
		cout<<"-";
		i=1;
	}		//20005
	int j=d.length()-1;
	for(j;j>i;j--)
	{
		count++;
		if(count%3==0 && count!=0)
		{
			d.insert(j,",");
		}
		
	}
	for(i;i<d.length();i++)
	{
		cout<<d[i];
	}
	return 0;
} 
