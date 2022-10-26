#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void main() 
{
	float r = 0;
	float p = 3.14f;//定义pai值
	float acre = 0;
	scanf("%f", &r);//输入半径r值
	acre = p * r * r;//计算公式
	printf("半径为%f的面积为%.2f",r, acre);
	return 0;
}

