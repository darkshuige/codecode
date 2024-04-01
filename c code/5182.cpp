#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int x=b-a;
    if(a<=12 && b>=13)
	 x--;
    if(a==12)
	 x++; 
    if(b==12 || b==24)
	 x--;
    cout<<x<<endl;
}
