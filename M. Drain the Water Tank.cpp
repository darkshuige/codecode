#include<iostream>
#include<algorithm>
using namespace std;
const int N=2010;
int n,ans;
typedef long long ll;
ll x[N],y[N];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	 cin>>x[i]>>y[i];
	for(int i=0,j=1;i<n;i++)
	{
		while(y[i]==y[j])
		 j=(j+1)%n;
		int pre=(i+n-1)%n;
		if(y[i]<y[pre] && y[i]<y[j])
		{
			if(y[i]!=y[(i+1)%n])
			{
				if((x[pre]<=x[i] && x[i]<x[j]) || (x[pre]<x[i] && x[i]<=x[j]))
				 ans++;
			}
			else 
			{
				if(x[(i+1)%n]>x[i])
				 ans++; 
			}
		}
	}
	cout<<ans<<endl;
}
