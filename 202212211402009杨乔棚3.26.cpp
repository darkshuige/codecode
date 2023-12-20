#include<iostream>
#include<string>
const double PI=3.14;
using namespace std;
class Stock
{
	public:
		Stock(string,int,double);
		void print();
	private:
		string stockcode;
		int quanity;
		double price;	
};
Stock::Stock(string q,int a=1000,double b=8.98)
{
	stockcode=q;
	quanity=a;
	price=b;
}
void Stock::print()
{
	cout<<this->stockcode<<" "<<this->quanity<<" "<<this->price<<endl;
}
int main()
{
	Stock op1("600001",3000,5.67);
	op1.print();
	Stock op2("600001");
	op2.print();
	return 0;
}
