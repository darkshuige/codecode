#include<stdio.h>
#include<string.h>
#include<math.h>
main()
{
int r,i,b=0,j=0;
char a[100000];
double sum=0;
scanf("%d",&r);
for(i=1;i<=r;i++) 
{
 scanf("%s",&a);  
 b=strlen(a);
 //a[b]='\0';
   j=0;
 if(a[0]=='-')
 {
  	j=1;
 }
 while(a[j]!='\0')
 {
  sum=sum+abs(a[j]-'0');
  j++;
 }
 j++;
 if(a[0]=='-')
 {
  b=b-1;
 }
 printf("number=%d,sum=%.0lf\n",b,sum);
 sum=0;
} 
return 0;
}
