
# include <stdio.h>
# include <string.h>
 
int main()
{
	int len, i, j, ok;
	char word[100];//�����ַ��������в������ո�
	while(scanf("%s", word)!=EOF)
	{
		len = strlen(word);
		for(i = 1; i <= len; i++)
		{
			if (len % i == 0)//��i��len�Ĺ�Լ��
			{
				ok = 1;
				for(j = i; j < len; j++)
				{
					if (word[j] != word[j % i])//�����ֶ�Ӧ���ַ�������ȣ�����Ϊ���ڴ�
					{
						ok = 0;
						break;
					}
				}
				if (ok)
				{
					printf("%d\n", i);
					break;
				}
			}
		}	
	}
	
 
	return 0;
}
