#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> VI;
VI A,B;
void mul(VI &A, VI &B, VI &C)
{
  for(int i=0; i<A.size(); i++)
    for(int j=0; j<B.size(); j++)
	{
      C[i+j] += A[i]*B[j];   //乘积
      C[i+j+1] += C[i+j]/10; //进位
      C[i+j] %= 10;          //余数      
    }
  while(C.size()>1&&!C.back()) C.pop_back();//前导0 
}
int main()
{
  string a, b;
  cin >> a >> b;
  for(int i=a.size()-1;~i;i--) A.push_back(a[i]-'0');
  for(int i=b.size()-1;~i;i--) B.push_back(b[i]-'0');
  VI C(A.size()+B.size());
  mul(A, B, C);
  for(int i=C.size()-1; ~i; i --) cout << C[i];
  return 0;
}