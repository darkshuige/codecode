#include<bits/stdc++.h>
using namespace std;
int main()
{
	double tz,sg;
	while(cin>>sg>>tz)
	{
		double BMI=tz/(pow(sg/100,2));
		int op=(int)((BMI+0.005)*100);
		if(op<1850)
		 cout<<"Underweight"<<endl;
		else if(op<2000)
		 cout<<"Normal"<<endl;
		else if(op<2500)
		 cout<<"Moderate"<<endl;
		else if(op<2800)
		 cout<<"Overweight"<<endl;
		else if(op<3200)
		 cout<<"Obesity"<<endl;
		else
		 cout<<"Very obese"<<endl;
	}
	return 0;
}
