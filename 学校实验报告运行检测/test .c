#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void main() 
{
	float r = 0;
	float p = 3.14f;//����paiֵ
	float acre = 0;
	scanf("%f", &r);//����뾶rֵ
	acre = p * r * r;//���㹫ʽ
	printf("�뾶Ϊ%f�����Ϊ%.2f",r, acre);
	return 0;
}

