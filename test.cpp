#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int a[4], b[4],ans=0;
void solve() {
	ans = 0;
	cin >> a[1] >> a[2] >> a[3];
	cin >> b[1] >> b[2] >> b[3];
	for (int i = 1; i <= 3; ++i) {
		if (a[i] <= b[i % 3 + 1]) ans += a[i], b[i % 3 + 1] -= a[i];
		else {
			ans += b[i % 3 + 1];
			a[i] -= b[i % 3 + 1];
			b[i % 3 + 1] = 0;
			if (a[i] <= b[i]) b[i] -= a[i];
			else {
				a[i] -= b[i];
				b[i] = 0;
				ans -= a[i%3+2];
				b[i%3+2] -= a[i];
			}
		}
		//cout << ans << endl;
	}
	cout << ans << endl;

}
int main() {
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}