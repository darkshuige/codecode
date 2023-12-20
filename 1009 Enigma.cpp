#include<cstdio>

#include<algorithm>
#include<cstring>
using namespace std;




int n;
int m;


char tmp[30];
char tra[5][30];
int code[5][30];
int con[3];
int main()
{
    int ff=0;
    int cas=1;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;


            if(ff)
                puts("");
            ff=1;
        printf("Enigma %d:\n",cas++);
        for(int i=0;i<3;i++)
        {
            scanf("%s",tra[i]);
            for(int j=0;j<n;j++)
                code[i][tra[i][j]-'A']=j-(tra[i][j]-'A');
        }
        scanf("%d",&m);
        char tmp[3000];


        for(int i=0;i<m;i++)
        {
            scanf("%s",tmp);


            int len=strlen(tmp);


            for(int j=0;j<len;j++)
            {
              int t=tmp[j]-'A';
                con[0]=j%n;
                con[1]=(j/n)%n;
                con[2]=(j/n/n)%n;
            for(int k=2;k>=0;k--)
              {
                  t+=code[k][(t-con[k]+n)%n];
                  t=t+n;
                  t%=n;
              }
              printf("%c",t+'a');


            }
            puts("");
        }




    }
    return 0;
}
