#include<bits/stdc++.h>
using namespace std;
int v[10];
int main()
{
	while ( cin >> v[0] ) 
	{
		for ( int i = 1 ; i < 9 ; ++ i )
			cin >> v[i];
		int flag = 0;
		for ( int i = 0 ; i < 9 ; ++ i )
			if ( v[i] ) 
			{
				if ( flag ) 
				{
					if ( v[i] < 0 )
						cout << " - ";
					else 
						cout << " + ";
				}
				else if ( !flag ) 
				{
					if ( v[i] < 0 )
						cout << "-";
					flag = 1;
				}
				if ( abs(v[i]) != 1 && i < 8 )
					cout << abs(v[i]);
				if ( i == 8 )
					cout << abs(v[i]);
				
				if ( i < 8 ) 
				{
					cout << "x";
					if ( i < 7 )
						cout << "^" << 8-i;
				}
			}
		if ( !v[0] && !v[1] && !v[2] && !v[3] && !v[4] && !v[5] && !v[6] && !v[7] && !v[8] )
			cout << 0;
		cout << endl;
	}
	return 0;
}
