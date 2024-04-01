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
		char a[105]={0},b[105]={0};
		cin>>a>>b;
		int l1=strlen(a),l2=strlen(b);
		int pos=-1;
		for(int i=0;i<l2;i++)
		{
			if(a[i]!=b[i])
			{
				pos=i;
				break;
			}
		}
		if(pos!=-1)
		 cout<<(l1-pos+(l2-pos))*n<<endl;
		else
		 cout<<abs(l2-l1)*n<<endl;
	}
	return 0;	
} 
