#include<bits/stdc++.h>
using namespace std;
const int maxn = 5000005;
long long n, p, q, m;
unsigned int SA, SB, SC;
unsigned rng61()
{
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t = SA;
    SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
}

int tot = 0;
int sum[maxn];
stack<long long>st;
void PUSH(int x) {
	if(st.empty()){
		tot++;
        st.push(x);
        sum[tot] = 0;
	}
    else if (x < st.top())
        sum[tot]++;
    else {
        tot++;
        st.push(x);
        sum[tot] = 0;
    }
    
}
void POP() {
	if(st.empty()){
		return ;
	}
    if (sum[tot] > 0) {
        sum[tot]--;
    }
    else if(!st.empty()){
        tot--;
        st.pop();
    }
}
void gen()
{
    while (!st.empty()) st.pop();
    tot = 0;
    long long ans = 0;
    cin>>n>>p>>q>>m>>SA>>SB>>SC;
    for (int i = 1; i <= n; i++)
    {
        if (rng61() % (p + q) < p)
        {
        	//cout<<1<<endl;
            PUSH(rng61() % m + 1);
        }
        else POP();
        if(!st.empty())
        ans ^= i * st.top();
        //cout<<ans<<endl;
    }
    cout << ans;

}

signed main() {
    int T;
    cin >> T;
    for(int  i=1;i<=T;++i){
        cout << "Case #" << i << ": ";
        gen();
        cout << endl;
    }
}