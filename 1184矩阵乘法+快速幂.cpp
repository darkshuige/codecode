#include<bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
struct matrix
{
	long long m[2][2];
};
matrix I//µ•Œªæÿ’Û 
{
	1,0,
	0,1
};
matrix A
{
	1,1,
	1,0
};
matrix matmul(matrix m1,matrix m2)//æÿ’Ûœ‡≥À 
{
	matrix temp;
	memset(temp.m,0,sizeof temp.m);
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				temp.m[i][j]=(temp.m[i][j]+m1.m[i][k]*m2.m[k][j])%mod;
			}
		}
	}
	return temp;
}
matrix ksm(matrix a,long long b)
{
	matrix ans=A,tmp=a;
	while(b>0)
	{
		if(b&1==1)
		{
			ans=matmul(ans,tmp);
		}
		tmp=matmul(tmp,tmp);
		b>>=1;
	}
	return ans;
}
int main()
{
	long long n;
	while(cin>>n)
	{
		if(n==1 || n==2)
		{
			cout<<1<<endl;
			continue;
		}
		matrix tmp;
		tmp=ksm(A,n-2);
		cout<<tmp.m[0][0]<<endl;
	}
	return 0;
}
