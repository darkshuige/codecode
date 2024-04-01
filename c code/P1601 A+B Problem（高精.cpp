#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> VI;
VI a, b, c;
int la,lb,lc;
void add(VI &a,VI &b,VI &c)
{
	int t=0;
	for(int i=0; i<lc; i++)
	{
		if(i<la) t+=a[i];
		if(i<lb) t+=b[i];
		c.push_back(t%10); //存余
		t/=10;             //进位
	}
	if(t) c.push_back(t);
}
int main()
{
	string sa,sb; cin>>sa>>sb;
	la=sa.size(); lb=sb.size(); lc=max(la,lb);
	for(int i=la-1;~i;i--) a.push_back(sa[i]-'0');
	for(int i=lb-1;~i;i--) b.push_back(sb[i]-'0');
	add(a,b,c);
	for(int i=c.size()-1;~i;i--) printf("%d", c[i]);
	return 0;
}