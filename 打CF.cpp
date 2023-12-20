#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--) 
	{
		string ans1,ans2;
        string s;
        cin >> s;
        int n = s.size();
        set<char> st;
        if (n % 2) 
		{
            for (int i = 0; i < n / 2; ++i) 
			{
                st.insert(s[i]);
            }
        } else {
            for (int i = 0; i < n / 2 + 1; ++i) 
			{
                st.insert(s[i]);
            }
        }
        st.size() != 1 ? ans1="YES": ans1="NO";
        map<char,bool>f;
		int cnt=0;
		int l=s.size();
		for(int i=0;i<s.size();i++)
		{
			if(!f[s[i]] && i!=l-i-1)
			{
				f[s[i]]=1;
				cnt++;
			}
		}
		if(cnt<=1)
		 ans2="NO";
		else
		 ans2="YES";
		if(ans1==ans2)
		 cout<<"YES"<<endl;
		else 
		 cout<<"NO"<<endl;
    }
	return 0;
} 
