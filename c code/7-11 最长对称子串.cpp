#include<stdio.h>
#include<string.h> 
int main()
{
	int a,b,c,num,max=0,n,m;
	char c1[1001];
	gets(c1);
	a=strlen(c1);
	for(b=0;b<a;b++)//��ʼѰ�ҶԳ��ִ� 
	{
		num=1;//��Ѱ�ҶԳ��ִ�Ϊ����ʱ 
		for(n=1,m=0;b-m>=0 && b+n+1<a;m++,n++)//�����鳤��Ϊѭ���ж���������b-m<0 || b+n+1>=a ѭ������ 
		{
			if(c1[b-m]==c1[b+n+1])//�ж��ַ��Ƿ���ȡ��Ƿ�Գ�	 
			{
				num+=2;//���Գ�ʱ������2. 
			}
			else
			break;
		}
		if(num>max)
		{
			max=num;//Ѱ�����ĶԳ��ִ����� 
		}
		
		
		num=0;//��Ѱ�ҶԳ��ַ���Ϊż��ʱ 
		for(n=1,m=0;b-m>=0 && b+n<a;m++,n++)//�����鳤��Ϊѭ���ж���������b-m<0 || b+n>=a ѭ������ 
		{
			if(c1[b-m]==c1[b+n])//�ж��ַ��Ƿ���ȡ��Ƿ�Գ�
			{
				num+=2;//���Գ�ʱ������2. 
			}
			else
			break;
		}
		if(num>max)
		{
			max=num;//Ѱ�����ĶԳ��ִ�����
		}
	}
	printf("%d",max);
} 
