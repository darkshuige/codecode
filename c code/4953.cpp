#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int a[15];
	while(cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]>>a[7]>>a[8]>>a[9])
	{
		int b[15],c[15],pos1=0,pos2=0;
		for(int i=0;i<10;i++)
		{
			if(a[i]%2==0)
			 b[pos1++]=a[i];
			else
			 c[pos2++]=a[i];
		}
		sort(b,b+pos1);
		sort(c,c+pos2,cmp);
		for(int i=0;i<pos2;i++)
		{
			if(i!=0)
			 cout<<" ";
			cout<<c[i];
		}
		for(int i=0;i<pos1;i++)
		 cout<<" "<<b[i];
		cout<<endl;
	}
	return 0;
} 
