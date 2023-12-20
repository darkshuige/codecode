#include<iostream>
using namespace std;
int preme[20000]={0};
bool v[20000]={0};
int c=1;
void ss()
{
	int i,j;
	for(i=2;i<=1000;i++)
	{
		if(v[i]==false)
		{
			preme[c++]=i;
		}
		for(j=1;j<=c && i*preme[j]<=1000;j++)
		{
			v[i*preme[j]]=true;
			if(i%preme[j]==0)
			 break;
		}
	}
}
int main()
{
	ss();
	int i;
	for(i=1;i<200;i++)
	{
		cout<<preme[i]<<endl;	
	}
	return 0;
}
