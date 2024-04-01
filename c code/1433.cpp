#include<bits/stdc++.h>
using namespace std;
int a1[5], a2[5];
int main() 
{
    int t;
    while (cin >> t) 
	{
        while (t--) 
		{
            int max1 = 0, max2 = 0;
            for (int i = 0;i < 5;i++) 
			{
                string a;
                int w = 0;
                cin >> a;
                int n = a.size();
                for (int i = 0;i < n;i++) 
				{
                    a[i] = toupper(a[i]);
                }
                if (a != "A" && a != "J" && a != "Q" && a != "K") 
				{
                    a1[i] = atoi(a.c_str());
                    w = a1[i];
                }
                else 
				{
                    if (a == "A") 
					{
                        w = 1;a1[i] = 1;
                    }
                    else 
					{
                        if (a == "J")w = 11;
                        if (a == "Q")w = 12;
                        if (a == "K")w = 13;
                        a1[i] = 10;
                    }
                }
                if (w > max1)max1 = w;
            }
            for (int i = 0;i < 5;i++) 
			{
                string a;
                int n;
                int w = 0;
                cin >> a;
                n = a.size();
                for (int i = 0;i < n;i++) 
				{
                    a[i] = toupper(a[i]);
                }
                if (a != "A" && a != "J" && a != "Q" && a != "K") 
				{
                    a2[i] = atoi(a.c_str());
                    w = a2[i];
                }
                else 
				{
                    if (a == "A") 
					{
                        w = 1;a2[i] = 1;
                    }
                    else 
					{
                        if (a == "J")w = 11;
                        if (a == "Q")w = 12;
                        if (a == "K")w = 13;
                        a2[i] = 10;
                    }
                }
                if (w > max2)max2 = w;
            }
            int x1 = 0, x2 = 0;
            sort(a1, a1 + 5);
            sort(a2, a2 + 5);  
            do {
                int sum1 = a1[0] + a1[1] + a1[2];
                int sum2 = a1[3] + a1[4];
                if (sum1 % 10 == 0) 
				{
                    if (sum2 % 10 == 0)x1 = 10;
                    else x1 = sum2 % 10;
                    break;
                }
            } while (next_permutation(a1, a1 + 5));
            do 
			{
                int sum1 = a2[0] + a2[1] + a2[2];
                int sum2 = a2[3] + a2[4];
                if (sum1 % 10 == 0) 
				{
                    if (sum2 % 10 == 0)x2 = 10;
                    else x2 = sum2 % 10;
                    break;
                }
            }while (next_permutation(a2, a2 + 5));
             if (x1 > x2)
			 cout << "-1" << endl;
            else if (x1 < x2)
			 cout << "1" << endl;
            else 
			{
                if (max1 > max2)cout << "-1" << endl;
                if (max1 < max2)cout << "1" << endl;
                if (max1 == max2)cout << "0" << endl;
            }
        }
    }
}
