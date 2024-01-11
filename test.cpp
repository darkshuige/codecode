#include<bits/stdc++.h>
using namespace std;
int N, first, mxLen; //数字，起点，最大的长度
//解题思路：外层遍历起点，里层遍历连续的因子，最后取最长的结果即可。
void Input() {
  ios::sync_with_stdio(false);
  cin >> N;
  int cmp = sqrt(N);
  for (int i = 2; i <= cmp; i++) {
    int t = N, start = i;
    while (t % start == 0) { //一旦出现不连续的情况直接跳出循环
      t /= start;
      start++;
    }
    if (start - i > mxLen) {
      mxLen = start - i;
      first = i;
    }
  }
}
void print() {
  if (mxLen) { //一旦能分解成多个就这样打印，否则就是没有更新，则输出1
    cout << mxLen << endl;
    cout << first;
    for (int i = 1; i < mxLen; i++) {
      cout << '*' << first + i;
    }
  }
  else {
    cout << 1 << endl;
    cout << N;
  }

}
int main() {
  Input();
  print();
  return 0;
}