#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int len;
} SeqList;

void build_list(SeqList* L) {
    printf("������˳���ĳ���: ");
    scanf("%d", &(L->len));
    printf("������ %d ����������: ", L->len);
    for (int i = 0; i < L->len; i++) {
        scanf("%d", &(L->data[i]));
    }
}

void insert_list(SeqList* L, int num) {
    int i = L->len - 1;
    while (i >= 0 && L->data[i] > num) {
        L->data[i + 1] = L->data[i];
        i--;
    }
    L->data[i + 1] = num;
    L->len++;
}

void insert_num(SeqList* L) {
    int num;
    printf("������Ҫ���������: ");
    scanf("%d", &num);
    insert_list(L, num);
}

void print_list(SeqList L) {
    printf("�µ�������������Ϊ: ");
    for (int i = 0; i < L.len; i++) {
        printf("%d ", L.data[i]);
    }
}

int main() {
    SeqList L;
    build_list(&L);
    insert_num(&L);
    print_list(L);
    return 0;
}
