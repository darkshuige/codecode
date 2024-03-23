#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int a[10001]; //质因子的个数

void decompose(int x){ //分解质因数
  for(int i=2; i*i<=x; i++)
    while(x%i==0) a[i]++, x/=i;
  if(x>1) a[x]++;
}
int main(){
  cin >> n;
  for(int i=2; i<=n; i++) decompose(i);
    for(int i=1;i<=n;i++)
    if(a[i]) cout<<i<<" "<<a[i]<<endl;
  return 0;
}