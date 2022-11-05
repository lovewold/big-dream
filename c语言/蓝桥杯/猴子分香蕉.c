#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	long i = 0;
	for (i = 1; i <= 99999; i+=5)
	{
		if (i % 5 == 1)
		{
			int j = ((i - 1) / 5)*4;
			if (j % 5 == 2)
			{
				int n = ((j - 2) / 5 )* 4;
				if (n % 5 == 3)
				{
					int z = ((j - 3) / 5) * 4;
					if (z % 5 == 4)
					{
						int t = ((z - 4) / 5) * 4;
						if(t % 5 == 0)
						{
							printf("%ld ", i);
							
						}
					}
				}
			}
		}
	}
	return 0;
}
