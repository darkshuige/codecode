#include<bits/stdc++.h>
using namespace std;
struct st
{
	string name;
	int age,fs;
};
int cmp(st a,st b)
{
	if(a.fs!=b.fs)
	 return a.fs<b.fs;
	else
	 if(a.name!=b.name)
	  return a.name<b.name;
     else
      return a.age<b.age;
}
int main()
{
	int n;
	while(cin>>n)
	{
		st a[1005];
		for(int i=0;i<n;i++)
		 cin>>a[i].name>>a[i].age>>a[i].fs;
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++)
		 cout<<a[i].name<<" "<<a[i].age<<" "<<a[i].fs<<endl;
	}
	return 0;
}
