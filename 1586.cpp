#include<bits/stdc++.h>
using namespace std;
class wj
{
	public:
		wj(int p,int c)
		{
			Price=p;
			Count=c;
			Total=p*c;
		}
		void show()
		{
			printf("Price=%d,Count=%d,Total=%d\n",Price,Count,Total);
		}
	private:
		int Price;
		int Count;
		int Total;
};
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		wj wj1(a,b);
		wj1.show();	
	}
	
	return 0;
}
