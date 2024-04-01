
# include <stdio.h>
# include <string.h>
 
int main()
{
	int len, i, j, ok;
	char word[100];//读入字符串，其中不包括空格
	while(scanf("%s", word)!=EOF)
	{
		len = strlen(word);
		for(i = 1; i <= len; i++)
		{
			if (len % i == 0)//若i是len的公约数
			{
				ok = 1;
				for(j = i; j < len; j++)
				{
					if (word[j] != word[j % i])//若发现对应的字符串不相等，即不为周期串
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
