#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 定义顾客结构体
typedef struct {
    int id;  // 顾客编号
    int window;  // 业务窗口编号，1表示窗口A，2表示窗口B
} Customer;

// 比较函数，用于排序顾客序列
int compare(const void* a, const void* b) {
    const Customer* c1 = (const Customer*)a;
    const Customer* c2 = (const Customer*)b;
    return c1->id - c2->id;
}

void processCustomers(int N, Customer* customers) {
    int i, j;
    int aCount = 0;  // 窗口A的顾客数量
    int bCount = 0;  // 窗口B的顾客数量

    // 统计窗口A和窗口B的顾客数量
    for (i = 0; i < N; i++) {
        if (customers[i].window == 1)
            aCount++;
        else
            bCount++;
    }



    // 输出顾客序列
    for (i = 0; i < N; i++) {
        // 当窗口A的顾客数量大于0时，先输出窗口A的顾客
        if (aCount > 0) {
            if (customers[i].window == 1) {
                printf("%d ", customers[i].id);
                aCount--;
            }
        }

        // 输出窗口B的顾客
        if (bCount > 0) {
            if (customers[i].window == 2) {
                printf("%d ", customers[i].id);
                bCount--;
            }
        }
    }
}

int main() {
    int N;  // 顾客总数
    int i;

    // 提示用户输入顾客总数
    printf("请输入顾客总数：");
    scanf("%d", &N);

    // 创建顾客数组
    Customer* customers = (Customer*)malloc(N * sizeof(Customer));

    // 提示用户输入顾客序列
    printf("请输入顾客序列（编号之间以空格分隔）：");
    for (i = 0; i < N; i++) {
        scanf("%d", &(customers[i].id));

        // 判断顾客的窗口编号
        if (customers[i].id % 2 == 0)
            customers[i].window = 2;
        else
            customers[i].window = 1;
    }

    // 处理顾客序列
    printf("业务处理顺序的顾客序列为：");
    processCustomers(N, customers);
    printf("\n");

    // 释放内存
    free(customers);

    return 0;
}
