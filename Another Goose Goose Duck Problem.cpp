#include<iostream>
using namespace std;
int main()
{//kҪɱ�ģ�b������ 
	int l,r,b,k;
	cin>>l>>r>>b>>k;
    int t=l/b*b;
    if (t<l)
        t+=b;
    cout<<k*t<<endl;
	return 0;
}
