#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	char arr[12][12] = 
	{"000000000000",
	"0UDDLUULRUL0",
	"0UURLLLRRRU0",
	"0RRUURLDLRD0",
	"0RUDDDDUUUU0",
	"0URUDLLRRUU0",
	"0DURLRLDLRL0",
	"0ULLURLLRDU0",
	"0RDLULLRDDD0",
	"0UUDDUDUDLL0",
	"0ULRDLUURRR0",
	"000000000000"};
	int i = 0;
	int j = 0;
	int z = 0;
	int count = 0;
	int a = 0; 
	int b = 0;
	for (i = 1; i <11; i++)
	{
		for (j = 1; j <11; j++)
		{
			a = i;
			b = j;
			for (z = 0; z < 10; z++)
			{
				if (arr[a][b] == 'U')
				{
					a--;
				}
				else if (arr[a][b] == 'D')
				{
					a++;
				}
				else if (arr[a][b] == 'R')
				{
					b++;
				}
				else if (arr[a][b] == 'L')
				{
					b--;
				}
				else if (arr[a][b] == '0')
				{
					count++;
					printf("(%d,%d)\n", i, j);
					break;
				}
				
			}
			
		}
	}
	printf("\n");
	printf("%d", count);
	return 0;
}
#include<stdio.h>
#include<string.h>

//int main()
//{
//	char ch[10][10];
//	strcpy(ch, "UDDLUULRULUURLLLRRRURRUURLDLRDRUDDDDUUUUURUDLLRRUUDURLRLDLRLULLURLLRDURDLULLRDDDUUDDUDUDLLULRDLUURRR");
//	int li;
//	int ha;
//	int i = 0;
//	int count = 0;
//	int count1 = 0;
//	while (i < 100)
//	{
//		for (li = i, ha = i; li < 10 && ha < 10;)
//		{
//			if (ch[li][ha] == 'U')
//			{
//				ha--;
//				count1++;
//			}
//			else if (ch[li][ha] == 'D')
//			{
//				ha++;
//				count1++;
//			}
//			else if (ch[li][ha] == 'R')
//			{
//
//				li++;
//				count1++;
//			}
//			else if (ch[li][ha] == 'L')
//			{
//				li--;
//				count1++;
//			}
//			if (count1 > 20)
//			{
//				break;
//			}
//
//		}
//		i++;
//		if (li > 10 || ha > 10)
//		{
//			count++;
//		}
//	}
//	printf("%d", count);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int n = 0;
//	scanf("%d", &n);
//	int a = 0;
//	int count1 = 0;
//	int count2 = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &a);
//		if (a >= 60)
//		{
//			count1++;
//		}
//		if (a >= 85)
//		{
//			count2++;
//		}
//	}
//	printf("%.0f%%\n", count1 * 100.0 / n+0.5);
//	printf("%.0f%%\n", count2 * 100.0 / n+0.5);
//
//	return 0;
//}