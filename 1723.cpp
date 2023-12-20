#include<bits/stdc++.h>
using namespace std;
int main()
{
	int sb[5];
	while(cin>>sb[0]>>sb[1]>>sb[2]>>sb[3])
	{
		char s1[5],s2[5],s3[5];
		scanf("%s%s%s",s1,s2,s3);
		int n=0;
		if (s1[0]=='+') n++;
		if (s2[0]=='+') n++;
		if (s3[0]=='+') n++;
		long long minn=INT_MAX;
		sort(sb,sb+4);
		if(n==0)
		{
			minn=sb[0]*sb[1]*sb[2]*sb[3];			
		}
		else if(n==1)
		{
			do
			{
				if(sb[0]+sb[1]*sb[2]*sb[3]<minn)
				 minn=sb[0]+sb[1]*sb[2]*sb[3];
			}
			while(next_permutation(sb,sb+4));
		}
		else if(n==2)
		{
			do
			{
				if(sb[0]+sb[1]+sb[2]*sb[3]<minn)
				 minn=sb[0]+sb[1]+sb[2]*sb[3];
			}
			while(next_permutation(sb,sb+4));
		}
		else if(n==3)
		{
			minn=sb[0]+sb[1]+sb[2]+sb[3];	
		}
		cout<<minn<<endl;
	}
	return 0;
}
