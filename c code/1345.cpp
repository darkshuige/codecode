#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int sx,sy,ex,ey;
		char op[5];
		scanf("%s",&op);
		sx=op[0]-'a';
		sy=op[1]-48;
		scanf("%s",&op);
		ex=op[0]-'a';
		ey=op[1]-48;
		int d1=0,d2=0,d3=0,d4=0;
		int x=abs(sx-ex);
		int y=abs(sy-ey); 
		if(x==0 && y==0)
		{
			printf("0 0 0 0\n");	
			continue;
		}
		d1+=min(x,y)+abs(x-y);
		int q=abs(x-y);
		if(x==0 || y==0 || x==y)
		 d2=1;
		else 
		 d2=2;
		if(x==0 || y==0)
		 d3=1;
		else 
		 d3=2;
		if(x==y)
		 d4=1;
		else if(q%2!=0)
		 d4=-1;
		else d4=2;
		printf("%d %d %d ",d1,d2,d3);
		if(d4==-1)
		 cout<<"Inf"<<endl;
		else 
		 cout<<d4<<endl;
	}
	return 0;
}
