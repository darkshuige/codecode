#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		getchar();
		for(int i=1;i<=n;i++)
		{
			string s,pro,host,port,path;
			getline(cin,s);
			int pos1=s.find("://");
			if(pos1!=string::npos)
			{
				string cut(s,0,pos1);
				pro=cut;
				s.erase(0,pos1+3);
			}
			int pos2=s.find(":");
			if(pos2!=string::npos)
			{
				string cut(s,0,pos2);
				host=cut;
				s.erase(0,pos2);
			}
			else
			{
				int pos3=s.find("/");
				if(pos3==string::npos)
				{
					host=s;
					s="";	
				}
				else
				{
					string cut(s,0,pos3);
					host=cut;
					s.erase(0,pos3+1);
				}
			}
			int pos3=s.find(":");
			if(pos3!=string::npos)
			{
				int pos4=s.find("/");
				if(pos4!=string::npos)
				{
					string cup(s,1,pos4-1);
					port=cup;
					s.erase(0,pos4+1);
				}
				else
				{
					string cup(s,1);
					port=cup;
					s="";
				}
			}
			else
			{
				port="default";
			}
			if(s.size()>0)
			{
				path=s;
			}
			else
			{
				path="default";
			}
			printf("URL #%d\n",i);
			cout<<"Protocol = "<<pro<<endl;
			cout<<"Host     = "<<host<<endl;
			cout<<"Port     = "<<port<<endl;
			cout<<"Path     = "<<path<<endl;
			cout<<endl;
		}	
	}
	
	return 0;
} 
