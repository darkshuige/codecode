#include<iostream>
using namespace std;

int main()
{
	int n,k;
	int t,i,j;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n>>k;
		if(k==0)
		{
			if(n%2==1)
			{
				cout<<"0"<<" ";
				n--;
			}
		}
		if(n%2==0 && k==0)
		{
			for(j=1;;j++)
			{
				if(n==0)
				 break;
				 if(j!=1)
				  cout<<" ";
				cout<<j<<" "<<-j;
				n-=2;
			}
		}
		else if(k!=0)
		{
			if(n%2==0)
			{
				cout<<"0"<<" ";
				n--;
			}
			if(n%2!=0)
			{
				cout<<k;
				n--;
				for(j=1;;j++)
				{
					if(j==k)
					 j++;
					if(n==0)
				 	 break;
					cout<<" ";
					cout<<j<<" "<<-j;
					n-=2;
				}
			}
//			else if(n%2==0)
//			{
//				if(k%2!=0)
//				{
//					cout<<k/2<<" "<<k/2+1;
//					n-=2;
//					for(j=1;;j++)
//					{
//						if(j==k/2)
//						 j+=2;
//						if(n==0)
//					 	 break;
//						cout<<" ";
//						cout<<j<<" "<<-j;
//						n-=2;
//					}
//				}
//				else if(k%2==0)
//				{
//					cout<<k/2-1<<" "<<k/2+1;
//					n-=2;
//					for(j=1;;j++)
//					{
//						if(j==k/2-1)
//						 j+=3;
//						if(n==0)
//					 	 break;
//						cout<<" ";
//						cout<<j<<" "<<-j;
//						n-=2;
//					}
//				}
//			}
		}
		cout<<endl;
	}
    return 0;
}
