#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=200000;
void scan(int &x)// ‰»Î
{
	x=0;int f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
inline void print(int x)
{
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
int x[maxn],y[maxn];
set<int>st1;set<int>st2;
signed main()
{
	//jiasu;
	int n;
	scan(n);
	for(int i=0;i<n;i++)
	{
		scan(x[i]);scan(y[i]);
		st1.insert(x[i]);st2.insert(y[i]);
	}
	sort(x,x+n);
	int x1=x[(n-1)/2],x2=x[(n-1)/2+1];
	int sum1=0,sum2=0,x3=x[0],sum3=0;
	for(int i=0;i<n;i++)
	{
		sum1+=abs(x1-x[i]);
		sum2+=abs(x2-x[i]);
		sum3+=abs(x3-x[i]);
	}
	if(sum3<=sum1 && sum3<=sum2) print(x3);
	else if(sum1<sum3 && sum1<=sum2) print(x1);
	else if(sum2<sum3 && sum2<sum1) print(x2);
	cout<<" ";
	sort(y,y+n);
	int y1=y[(n-1)/2],y2=y[(n-1)/2+1];
	int y3=y[0];sum1=0,sum2=0,sum3=0;
	for(int i=0;i<n;i++)
	{
		sum1+=abs(y1-y[i]);
		sum2+=abs(y2-y[i]);
		sum3+=abs(y3-y[i]);
	}
	if(sum3<=sum1 && sum3<=sum2) print(y3);
	else if(sum1<sum3 && sum1<=sum2) print(y1);
	else if(sum2<sum3 && sum2<sum1) print(y2);
	cout<<endl;
} 
