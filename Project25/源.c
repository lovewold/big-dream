#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// ����˿ͽṹ��
typedef struct {
    int id;  // �˿ͱ��
    int window;  // ҵ�񴰿ڱ�ţ�1��ʾ����A��2��ʾ����B
} Customer;

// �ȽϺ�������������˿�����
int compare(const void* a, const void* b) {
    const Customer* c1 = (const Customer*)a;
    const Customer* c2 = (const Customer*)b;
    return c1->id - c2->id;
}

void processCustomers(int N, Customer* customers) {
    int i, j;
    int aCount = 0;  // ����A�Ĺ˿�����
    int bCount = 0;  // ����B�Ĺ˿�����

    // ͳ�ƴ���A�ʹ���B�Ĺ˿�����
    for (i = 0; i < N; i++) {
        if (customers[i].window == 1)
            aCount++;
        else
            bCount++;
    }



    // ����˿�����
    for (i = 0; i < N; i++) {
        // ������A�Ĺ˿���������0ʱ�����������A�Ĺ˿�
        if (aCount > 0) {
            if (customers[i].window == 1) {
                printf("%d ", customers[i].id);
                aCount--;
            }
        }

        // �������B�Ĺ˿�
        if (bCount > 0) {
            if (customers[i].window == 2) {
                printf("%d ", customers[i].id);
                bCount--;
            }
        }
    }
}

int main() {
    int N;  // �˿�����
    int i;

    // ��ʾ�û�����˿�����
    printf("������˿�������");
    scanf("%d", &N);

    // �����˿�����
    Customer* customers = (Customer*)malloc(N * sizeof(Customer));

    // ��ʾ�û�����˿�����
    printf("������˿����У����֮���Կո�ָ�����");
    for (i = 0; i < N; i++) {
        scanf("%d", &(customers[i].id));

        // �жϹ˿͵Ĵ��ڱ��
        if (customers[i].id % 2 == 0)
            customers[i].window = 2;
        else
            customers[i].window = 1;
    }

    // ����˿�����
    printf("ҵ����˳��Ĺ˿�����Ϊ��");
    processCustomers(N, customers);
    printf("\n");

    // �ͷ��ڴ�
    free(customers);

    return 0;
}
