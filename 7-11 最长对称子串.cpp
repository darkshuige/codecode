#include<stdio.h>
#include<string.h> 
int main()
{
	int a,b,c,num,max=0,n,m;
	char c1[1001];
	gets(c1);
	a=strlen(c1);
	for(b=0;b<a;b++)//开始寻找对称字串 
	{
		num=1;//当寻找对称字串为奇数时 
		for(n=1,m=0;b-m>=0 && b+n+1<a;m++,n++)//以数组长度为循环判断条件，当b-m<0 || b+n+1>=a 循环结束 
		{
			if(c1[b-m]==c1[b+n+1])//判断字符是否相等。是否对称	 
			{
				num+=2;//当对称时，自增2. 
			}
			else
			break;
		}
		if(num>max)
		{
			max=num;//寻找最大的对称字串长度 
		}
		
		
		num=0;//当寻找对称字符串为偶数时 
		for(n=1,m=0;b-m>=0 && b+n<a;m++,n++)//以数组长度为循环判断条件，当b-m<0 || b+n>=a 循环结束 
		{
			if(c1[b-m]==c1[b+n])//判断字符是否相等。是否对称
			{
				num+=2;//当对称时，自增2. 
			}
			else
			break;
		}
		if(num>max)
		{
			max=num;//寻找最大的对称字串长度
		}
	}
	printf("%d",max);
} 
