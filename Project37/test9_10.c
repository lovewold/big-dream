#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char str[] = "Hello world!";
//	char* pch;
//	pch = strrchr(str, 'o');
//	printf("Last occurence of 'o' found at %d \n", pch - str + 1);
//	return 0;
//}
//
///* strpbrk example */
//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//    char str[] = "This is a sample string";
//    char key[] = "aeiou";
//    char* pch;
//    printf("Vowels in '%s': ", str);
//    pch = strpbrk(str, key);
//    while (pch != NULL)
//    {
//        printf("%c ", *pch);
//        pch = strpbrk(pch + 1, key);
//    }
//    printf("\n");
//    return 0;
//}
/* strspn example */
#include <stdio.h>
#include <string.h>

//int main()
//{
//	char str[] = "22xxx";
//	char keys[] = "000001x";
//	int i;
//	i = strcspn(str, keys);
//	printf("The first number in str is at position %d.\n", i+1);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//    //192.168.0.1
//    //192 168 0 1 - strtok
//
//    char ip[] = "192.168.0.1";
//    char* ret = strtok(ip, ".");
//    printf("%s\n", ret);
//
//    ret = strtok(NULL, ".");
//    printf("%s\n", ret);
//
//    ret = strtok(NULL, ".");
//    printf("%s\n", ret);
//
//    ret = strtok(NULL, ".");
//    printf("%s\n", ret);
//
//    return 0;
//}
	//char* ret = strtok(copy, sep);
	//printf("%s\n", ret);
	//
	//ret = strtok(NULL, sep);
	//printf("%s\n", ret);

	//ret = strtok(NULL, sep);
	//printf("%s\n", ret);

#include <stdio.h>
#include <string.h>

int main()
{

    char arr[] = "1008611100@qq.com";
    printf("ԭ�ַ���: %s\n", arr);

    const char* sep = "@."; // ������ʶsep
    char arr1[30];
    char* ret = NULL;
    strcpy(arr1, arr); // �����ݿ���һ�ݣ�����arr���������

    // ���д�ӡ�и�����
    for (ret = strtok(arr, sep); ret != NULL; ret = strtok(NULL, sep)) 
    {
        printf("%s\n", ret);
    }

    printf("������ԭ���ݣ�%s\n", arr1); // �����arr���������
    printf("�ָ��ԭ�ַ������ƻ�: %s\n", arr); // �ָ��ԭ�ַ���������һ���ָ��ǰ���ַ�

    return 0;
}