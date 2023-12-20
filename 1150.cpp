#include<iostream>
using namespace std;
int a[]={0,0,1,7,4,2,0,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888};
int main()
{
	int n;
	while(cin>>n)
	{
		if(n<=21)
		{
			cout<<a[n]<<endl;
		}
		else
		{
			int x,y;
			x=(n-14)%7;
            y=(n-14)/7;
            cout<<a[x+14];
            while(y--)
            {
                cout<<8;
            }
            cout<<endl;
        }
	}
	return 0;
}
