#include<iostream>
const double PI=3.14;
using namespace std;
class cylinder
{
	public:
		cylinder(double,double);
		void vol();
	private:
		double r,h;
};
cylinder::cylinder(double r1,double h1)
{
	r=r1;
	h=h1;
}
void cylinder::vol()
{
	cout<<r*r*PI*h;
}
int main()
{
	double a,b;
	cin>>a>>b;
	cylinder op(a,b);
	op.vol();
	return 0;
} 
