#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
using namespace std;
typedef struct
{
 unsigned int weight;
 unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree;
typedef char * *HuffmanCode;
void Select(HuffmanTree HT,int n,int &s1,int &s2)
{
	int j;
	s1=0,s2=0;
	for(s1=1;s1<=n;s1++)
	if(0==HT[s1].parent)
	 break;
	else
	 return;
	for(j=1+s1;j<=n;j++)
	 if(HT[s1].weight>HT[j].weight&&0==HT[j].parent)
	  s1=j;
	for(j=1;j<s1;j++)
	 if(HT[s2].weight>HT[j].weight&&0==HT[j].parent)
	  s2=j;
	for(j=s1+1;j<=n;j++)
	 if(HT[s2].weight>HT[j].weight&&0==HT[j].parent)
	  s2=j;   
}
void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int w[],int n)
{
	if(n<=1)return;
	int m=2*n-1; 
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
	int p;int i;
	for(p=1,i=1;i<=n;++i,++p)
	{
		HT[p].weight=w[i-1];
		HT[p].parent=0;  
		HT[p].lchild=0;
		HT[p].rchild=0; 
	} 
	for(;i<=m;++i,++p)
	{
		HT[p].weight=0;
		HT[p].parent=0;  
		HT[p].lchild=0;
		HT[p].rchild=0;
	}
	for(i=n+1;i<=m;++i)
	{
		int s1,s2;
		Select(HT,i-1,s1,s2);
		HT[s1].parent=i;HT[s2].parent=i;
		HT[i].lchild=s1;HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
	}
	HC=(HuffmanCode)malloc((n+1)*sizeof(char *));
	char cd[n];
	cd[n-1]='\0';
	int c,f;
	int start;
	for(i=1;i<=n;++i)
	{
		start=n-1;
		for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
		{
			if(c==HT[f].lchild) cd[--start]='0';
			else cd[--start]='1';
		}
		HC[i]=(char *)malloc((n-start)*sizeof(char));
		strcpy(HC[i],&cd[start]);
	} 
}

void HuffmanCoding2(HuffmanTree &HT,HuffmanCode &HC,int *w,int n)
{
	if(n<=1) return ;
	int m=2*n-1;
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
	HC=(HuffmanCode)malloc((n+1)*sizeof(char *));
	int i;
	int p;
	for(int i=1;i<=m;++i) HT[i].weight=0;
	char cd[n];
	p=m;int cdlen=0;
	while(p)
	{
		if(HT[p].weight==0)
		{
			HT[p].weight=1;
			if(HT[p].lchild!=0)
			{
				p=HT[p].lchild;
				cd[cdlen++]='0';
			}
			else if(HT[p].rchild==0)
			{
				HC[p]=(char *)malloc((cdlen+1)*sizeof(char));
				cd[cdlen]='\0'; strcpy(HC[p],cd);
			}
		}
		else if(HT[p].weight==1)
		{
			HT[p].weight=2;
			if(HT[p].rchild!=0)
			{
				p=HT[p].rchild;
				cd[cdlen++]='1';
			}
			else
			{
				HT[p].weight=0;
				p=HT[p].parent;
				--cdlen;
			}
		}
	}
}
int main()
{
	HuffmanTree HT;
	HuffmanCode HC;
	int w[4]={7,5,2,4};
	HuffmanCoding(HT,HC,w,4);
	for(int i=1;i<=4;i++)
	 cout<<HC[i]<<endl;
	cout<<endl;
	int ww[4]={7,5,2,4};
	HuffmanCoding2(HT,HC,ww,4);
	for(int i=1;i<=4;i++)
	 cout<<HC[i]<<endl;
 return 0;
} 
