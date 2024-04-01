#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
    	int n;
    	cin>>n;
    	int sum=0;
    	for(int j=0;j<n;j++)
    	{
    		double x,y;
    		cin>>x>>y;
    		double r=pow(x,2)+pow(y,2);
    		if(r<=400) sum=sum+10;
			if(r>400&&r<=1600) sum=sum+9;
			if(r>1600&&r<=3600) sum=sum+8;
			if(r>3600&&r<=6400) sum=sum+7;
			if(r>6400&&r<=10000) sum=sum+6;
			if(r>10000&&r<=14400) sum=sum+5;
			if(r>14400&&r<=140*140) sum=sum+4;
			if(r>140*140&&r<=160*160) sum=sum+3;
			if(r>160*160&&r<=180*180) sum=sum+2;
			if(r>180*180&&r<=40000) sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
}
