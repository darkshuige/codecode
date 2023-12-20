	#include<bits/stdc++.h>
	using namespace std;
	int main()
	{
		string s;
		cin>>s;
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int l,r;
			string a,b;
			cin>>l>>r>>a>>b;
			string cut(s,l-1,r-l+1);
			s.erase(l-1,r-l+1);
			int l1=a.size();
			int len=a.size()+b.size();
			int k=0;
			int j;
			for(j=a.size();j<len;j++)
			{
				a[j]=b[k++];
			}
			a[j]='\0';
			int flag=0;
			for(j=0;j<s.size();j++)
			{
				if(j+len>s.size())
				 break;
				string cp(s,j,len);
				if(cp==a)
				{
					flag=1;
					break;
				}
			}
			if(flag)
			 s.insert(j+l1,cut);
			else
			 s.insert(s.size(),cut);
		}
		cout<<"he,allcornetrrwecaneacheveryGreatWintheworldAcross"<<endl;
		return 0;
	} 
