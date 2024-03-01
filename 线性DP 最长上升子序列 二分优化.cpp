#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=2000;
//b数组中的元素与最长上升子序列不同但是长度相同
int a[maxn],b[maxn];//a是原数组，b是有序数组
int len;//长度
int find(int x)//二分查找第一个大于等于x的数的位置在b中
{
	int l=1,r=len;
	int ans;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(x>b[mid]) l=mid+1;
		else
		{
			ans=mid;
			r=mid-1;
		}
	}
	return ans;
}
signed main()
{
	jiasu;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	 cin>>a[i];
	len=1;
	b[0]=a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i]>b[len])
		 b[++len]=a[i];
		else
		{
			int j=find(a[i]);
			b[j]=a[i];
		}
	}
	cout<<len<<endl;
	return 0;
}