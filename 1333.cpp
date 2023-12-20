#include<bits/stdc++.h>
using namespace std;
int main()
{
	int vul,d;
	cin>>vul>>d;
	int i=1;
	int count=0;
	while(vul)
	{
		for(int j=1;j<=i;j++)
		{
			vul-=d;
			count++;
			if(vul<=0)
			 break;
		}
		if(vul<=0)
		 break;
		count++;
		i++;
	}
	cout<<count<<endl;
	return 0;
}
