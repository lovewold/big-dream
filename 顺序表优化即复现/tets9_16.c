#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"

void menu()
{
	printf("*********************************************\n");
	printf("*********** 1 .头插   2.尾插   **************\n");
	printf("*********** 3. 头删   4.尾删   **************\n");
	printf("*********** 5.清空顺序表       **************\n");
	printf("*********** 6.插入值           **************\n");
	printf("*********** 7.删除值           **************\n");
	printf("*********** 8.寻找值           **************\n");
	printf("*********************************************\n");

}

int main()
{
    SL ps;
    SLinit(&ps); // 初始化顺序表

    int choice;
    SLDatEType value, insertValue;
    int pos, findResult;
    menu();

    while (1)
    {
        printf("请选择操作：");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("退出程序。\n");
            SLDestroy(&ps); // 销毁顺序表
            exit(0);
            break;

        case 1:
            printf("请输入要头插的值：");
            scanf("%d", &value);
            SLPushFront(&ps, value);
            printf("头插成功。\n");
            PrintfList(&ps);
            break;

        case 2:
            printf("请输入要尾插的值：");
            scanf("%d", &value);
            SLPushBack(&ps, value);
            printf("尾插成功。\n");
            PrintfList(&ps);

            break;

        case 3:
            SLPopFront(&ps);
            printf("头删成功。\n");
            PrintfList(&ps);

            break;

        case 4:
            SLPopBack(&ps);
            printf("尾删成功。\n");
            PrintfList(&ps);

            break;

        case 5:
            SLDestroy(&ps);
            printf("顺序表已清空。\n");
            PrintfList(&ps);

            break;

        case 6:
            printf("请输入要插入的位置和值（例如：位置 值）：");
            scanf("%d %d", &pos, &insertValue);
            SeqListIsert(&ps, pos, insertValue);
            printf("插入成功。\n");
            PrintfList(&ps);

            break;

        case 7:
            printf("请输入要删除的值：");
            scanf("%d", &value);
            int ret = SeqListFind(&ps, value);
            SeqListErase(&ps, ret);
            printf("删除成功。\n");
            PrintfList(&ps);

            break;

        case 8:
            printf("请输入要查找的值：");
            scanf("%d", &value);
            findResult = SeqListFind(&ps, value);
            PrintfList(&ps);

            if (findResult != -1)
                printf("值 %d 在位置 %d 处找到。\n", value, findResult);
            else
                printf("值 %d 未找到。\n", value);

            break;

        default:
            printf("无效的选择，请重新输入。\n");
            break;
        }
    }

    return 0;
}