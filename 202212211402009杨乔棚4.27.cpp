#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1 | 1
using namespace std;
const int maxn=200005;
typedef struct
{
	char *ch;
	int length;
}hstring;
int strassign(hstring &t,char *chars)
{
	//if(t.ch) free(t.ch);
	int i;auto c=chars;
	for(i=0,c=chars;*c;++i,++c);
	if(!i)
	{
		t.ch=NULL; t.length=0;
	}
	else
	{
		if(!(t.ch=(char*)malloc(i*sizeof(char))))
		 exit(0);
		for(int j=0;j<i;j++) t.ch[j]=chars[j];
		t.length=i;
	}
	return 1;
}
void Index1(hstring S,hstring T,int &cnt)//ÆÓËØÆ¥Åä 
{
	int i=0,j=0;
	int orin=0;
	while(j-1!=T.length)
	{
		if(S.ch[i]==T.ch[j])
		{
			i++;j++;
		}
		else
		{
			j=1;i=orin+1;orin++;
		}
		cnt++;
	}
}
void Index2(hstring S,hstring T,int &cnt)//¸Ä½øÆ¥Åä 
{
	int i=0,j=0,k=T.length-1,l=T.length-1;
	int orin=0;
	while(j<=k)
	{
		if(S.ch[i]==T.ch[j] && S.ch[l]==T.ch[k])
		{
			i++;j++;k--;l--;
		}
		else
		{
			j=0;k=T.length-1;
			i=orin+1;orin++;
			l=i+k;
		}
		cnt++;
	}
}
signed main()
{
	jiasu;
	hstring T,S;
	char s1[]="0000000000000000000000001";
	strassign(S,s1);
	char s2[]="00000000001";
	strassign(T,s2);
	int cnt1=0,cnt2=0;
	Index1(S,T,cnt1);
	Index2(S,T,cnt2);
	cout<<cnt1<<" "<<cnt2<<endl;
	return 0;
} 
