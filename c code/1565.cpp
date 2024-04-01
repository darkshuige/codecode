#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int row,line;
		cin>>row>>line;
		cout<<row*(row+1)*line*(line+1)/4<<endl;
	}
	return 0;
}
