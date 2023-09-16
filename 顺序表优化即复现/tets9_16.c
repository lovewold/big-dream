#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"

void menu()
{
	printf("*********************************************\n");
	printf("*********** 1 .ͷ��   2.β��   **************\n");
	printf("*********** 3. ͷɾ   4.βɾ   **************\n");
	printf("*********** 5.���˳���       **************\n");
	printf("*********** 6.����ֵ           **************\n");
	printf("*********** 7.ɾ��ֵ           **************\n");
	printf("*********** 8.Ѱ��ֵ           **************\n");
	printf("*********************************************\n");

}

int main()
{
    SL ps;
    SLinit(&ps); // ��ʼ��˳���

    int choice;
    SLDatEType value, insertValue;
    int pos, findResult;
    menu();

    while (1)
    {
        printf("��ѡ�������");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("�˳�����\n");
            SLDestroy(&ps); // ����˳���
            exit(0);
            break;

        case 1:
            printf("������Ҫͷ���ֵ��");
            scanf("%d", &value);
            SLPushFront(&ps, value);
            printf("ͷ��ɹ���\n");
            PrintfList(&ps);
            break;

        case 2:
            printf("������Ҫβ���ֵ��");
            scanf("%d", &value);
            SLPushBack(&ps, value);
            printf("β��ɹ���\n");
            PrintfList(&ps);

            break;

        case 3:
            SLPopFront(&ps);
            printf("ͷɾ�ɹ���\n");
            PrintfList(&ps);

            break;

        case 4:
            SLPopBack(&ps);
            printf("βɾ�ɹ���\n");
            PrintfList(&ps);

            break;

        case 5:
            SLDestroy(&ps);
            printf("˳�������ա�\n");
            PrintfList(&ps);

            break;

        case 6:
            printf("������Ҫ�����λ�ú�ֵ�����磺λ�� ֵ����");
            scanf("%d %d", &pos, &insertValue);
            SeqListIsert(&ps, pos, insertValue);
            printf("����ɹ���\n");
            PrintfList(&ps);

            break;

        case 7:
            printf("������Ҫɾ����ֵ��");
            scanf("%d", &value);
            int ret = SeqListFind(&ps, value);
            SeqListErase(&ps, ret);
            printf("ɾ���ɹ���\n");
            PrintfList(&ps);

            break;

        case 8:
            printf("������Ҫ���ҵ�ֵ��");
            scanf("%d", &value);
            findResult = SeqListFind(&ps, value);
            PrintfList(&ps);

            if (findResult != -1)
                printf("ֵ %d ��λ�� %d ���ҵ���\n", value, findResult);
            else
                printf("ֵ %d δ�ҵ���\n", value);

            break;

        default:
            printf("��Ч��ѡ�����������롣\n");
            break;
        }
    }

    return 0;
}