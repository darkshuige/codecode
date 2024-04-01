#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while(cin>>s)
	{
		stringstream ss;
		ss<<s;
		double a[200]={0};
		double sum=0,num;
		int pos=1;
		ss>>num;
		a[0]=num;
		char op;
		int flag=1;
		while(ss>>op>>num)
		{
			if(op=='+')
			{
				a[pos++]=num;
			}
			else if(op=='-')
			{
				a[pos++]=-num;
			}
			else if(op=='*')
			{
				a[pos-1]*=num;
			}
			else if(op=='/')
			{
				if(num==0)
				{
					flag=0;
					break;
				}
				else
				{
					a[pos-1]/=num;
				}
			}
		}
		if(flag==0)
		 cout<<"DivByZero"<<endl;
		else
		{
			for(int i=0;i<pos;i++)
			 sum+=a[i];
			printf("%e\n",sum);	
		}
	}
	return 0;
}
