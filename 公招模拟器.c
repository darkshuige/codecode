#include<stdio.h>
//a      b      c    d     e     f     g      h
//狙击 术士，先锋，近卫，重装，医疗，辅助，特种
//A 	 B 		C 	  D 	E 	 F 		G 		H 		I 	 J 		K 	 L 		M
//输出，防护，生存，治疗，群攻，减速，支援，快速复活，削弱，位移，爆发，召唤，控场
//6
//高级资深干员
//5
//资深干员，召唤+支援，辅助+削弱，生存+特种，术士+爆发
//4
//特种，支援，快速复活，防护+重装，治疗+群攻，先锋+输出
int main()
{
	int i,t;
	char a[3];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%s",&a);
		if(a[0]=='3' || a[1]=='3' || a[2]=='3')
		{
			printf("6\n");
			continue;
		}
		if((a[0]=='2' || a[1]=='2' || a[2]=='2'))
		{
			printf("5\n");
			continue;
		}
		if((a[0]=='G' || a[1]=='G' || a[2]=='G') && (a[0]=='L' || a[1]=='L' || a[2]=='L'))
		{
			printf("5\n");
			continue;
		}
		if((a[0]=='g' || a[1]=='g' || a[2]=='g') && (a[0]=='I' || a[1]=='I' || a[2]=='I'))
		{
			printf("5\n");
			continue;
		}
		if((a[0]=='C' || a[1]=='C' || a[2]=='C') && (a[0]=='h' || a[1]=='h' || a[2]=='h'))
		{
			printf("5\n");
			continue;
		}
		if((a[0]=='b' || a[1]=='b' || a[2]=='b') && (a[0]=='K' || a[1]=='K' || a[2]=='K'))
		{
			printf("5\n");
			continue;
		}
		if((a[0]=='h' || a[1]=='h' || a[2]=='h'))
		{
			printf("4\n");
			continue;
		}
		if((a[0]=='G' || a[1]=='G' || a[2]=='G'))
		{
			printf("4\n");
			continue;
		}
		if((a[0]=='H' || a[1]=='H' || a[2]=='H'))
		{
			printf("4\n");
			continue;
		}
		if((a[0]=='e' || a[1]=='e' || a[2]=='e') && (a[0]=='B' || a[1]=='B' || a[2]=='B'))
		{
			printf("4\n");
			continue;
		}
		if((a[0]=='D' || a[1]=='D' || a[2]=='D') && (a[0]=='E' || a[1]=='E' || a[2]=='E'))
		{
			printf("4\n");
			continue;
		}
		if((a[0]=='c' || a[1]=='c' || a[2]=='c') && (a[0]=='A' || a[1]=='A' || a[2]=='A'))
		{
			printf("4\n");continue;
		}
		printf("3\n");
	}
	return 0;
}
