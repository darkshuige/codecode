#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	getchar();
	for(int i=0;i<t;i++)
	{
		string s;
		getline(cin,s);
		if(s=="gcd")
		 cout<<"Greatest common factor"<<endl;
		else if(s=="Fast exponentiation algorithm")
		 cout<<"Fast exponentiation"<<endl;
		else if(s=="Disjoint Set Union")
		 cout<<"Element grouping"<<endl;
		else if(s=="Dijkstra")
		 cout<<"Shortest path"<<endl;
		else if(s=="kmp")
		 cout<<"Pattern string matching"<<endl;
		else if(s=="manacher")
		 cout<<"Palindrome"<<endl;
		else if(s=="prim")
		 cout<<"Minimum spanning tree"<<endl;
		else if(s=="Hungarian algorithm")
		 cout<<"Bipartite graph matching"<<endl;
		else if(s=="segment tree")
		 cout<<"Interval maintenance"<<endl;
		else if(s=="Nim")
		 cout<<"game"<<endl;
		else if(s=="Polynomial")
		 cout<<"Dogs don't learn"<<endl;
	}
    return 0;
}
