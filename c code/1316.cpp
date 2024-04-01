#include<bits/stdc++.h>
using namespace std;
char s[510];
int main()
{
    while(~scanf("%s", s))
	{
        int l = strlen(s);
        int cnt = 0;
        for(int i = 0; i < l; i++)
		{
            if((i!=l-1) && (s[i]!='0') && (s[i+1]!='7') && (((s[i]-'0')*10+(s[i+1]-'0'))%7==0))
			{
                cnt += 2;
                i++;
            }
			else if(s[i]=='7')
			{
                cnt++;
            }
			else
			{
                continue;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
