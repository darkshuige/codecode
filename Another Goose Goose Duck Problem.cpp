#include<iostream>
using namespace std;
int main()
{//k要杀的，b见面间隔 
	int l,r,b,k;
	cin>>l>>r>>b>>k;
    int t=l/b*b;
    if (t<l)
        t+=b;
    cout<<k*t<<endl;
	return 0;
}
