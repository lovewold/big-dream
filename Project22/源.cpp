#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100  // ����˳������󳤶�

// ����ͼ���¼�ṹ������
typedef struct BookRecord {
    int id;            // ��¼��
    char name[20];     // ����
    char author[20];   // ����
    char publisher[20];// ������
    float price;       // �۸�
}BookRecord;

// ����˳���ṹ������
typedef struct SeqList {
    BookRecord data[MAXSIZE]; // �洢˳���Ԫ�ص�����
    int length;               // ��ǰ˳���ĳ���
}SeqList;

// ��ʼ��˳���
void InitList(SeqList* L) {
    L->length = 0;  // ��˳����ȳ�ʼ��Ϊ 0
}

// ����˳���Ԫ��
void InputElement(SeqList* L) {
    BookRecord book;
    printf("�������¼��: ");
    scanf("%d", &book.id);
    printf("����������: ");
    scanf("%s", book.name);
    printf("����������: ");
    scanf("%s", book.author);
    printf("�����������: ");
    scanf("%s", book.publisher);
    printf("������۸�: ");
    scanf("%f", &book.price);
    L->data[L->length] = book;
    L->length++;   // ��˳����ȼ� 1
}

// ���˳���Ԫ��
void PrintList(SeqList L) {
    printf("���\t��¼��\t\t����\t\t����\t\t������\t\t�۸�\n");
    for (int i = 0; i < L.length; i++) {
        printf("%d\t%d\t\t%s\t\t%s\t\t%s\t\t%.2f\n", i + 1, L.data[i].id, L.data[i].name, L.data[i].author, L.data[i].publisher, L.data[i].price);
    }
}

// ����Ԫ�ص�λ��
int LocateElement(SeqList L, int id) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i].id == id) {
            return i + 1;  // �ҵ�Ԫ�أ���������˳����е�λ�ã��� 1 ��ʼ��
        }
    }
    return 0;  // û���ҵ�Ԫ�أ����� 0
}

// ��ָ��λ�ò�����Ԫ��
void InsertElement(SeqList* L, int pos) {
    if (pos < 1 || pos > L->length + 1) {  // �жϲ���λ���Ƿ�Ϸ�
        printf("����λ�÷Ƿ���\n");
        return;
    }
    BookRecord book;
    printf("�������¼��: ");
    scanf("%d", &book.id);
    printf("����������: ");
    scanf("%s", book.name);
    printf("����������: ");
    scanf("%s", book.author);
    printf("�����������: ");
    scanf("%s", book.publisher);
    printf("������۸�: ");
    scanf("%f", &book.price);
    // ��ָ��λ�ò�����Ԫ��
    for (int i = L->length; i >= pos; i--) {
        L->data[i] = L->data[i - 1];
    }
    L->data[pos - 1] = book;
    L->length++;  // ��˳����ȼ� 1
    printf("����ɹ���\n");
}

// ɾ��ָ��λ�õ�Ԫ��
void DeleteElement(SeqList* L, int pos) {
    if (pos < 1 || pos > L->length) { // �ж�ɾ��λ���Ƿ�Ϸ�
        printf("ɾ��λ�÷Ƿ���\n");
        return;
    }
    // ��ָ��λ��ɾ��Ԫ��
    for (int i = pos - 1; i < L->length - 1; i++) {
        L->data[i] = L->data[i + 1];
    }
    L->length--; // ��˳����ȼ� 1
    printf("ɾ���ɹ���\n");
}

// ������
int main() {
    SeqList L;
    int choice, pos, id;
    InitList(&L); // ��ʼ��˳���
    do {
        printf("��ѡ��Ҫִ�еĲ�����\n");
        printf("1. ����\n");
        printf("2. ���\n");
        printf("3. ����\n");
        printf("4. ����\n");
        printf("5. ɾ��\n");
        printf("6. �˳�����\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            InputElement(&L); // ����˳���Ԫ��
            break;
        case 2:
            PrintList(L); // ���˳���Ԫ��
            break;
        case 3:
            printf("������Ҫ���ҵĵ�¼�ţ�");
            scanf("%d", &id);
            pos = LocateElement(L, id); // ����Ԫ�ص�λ��
            if (pos) {
                printf("��Ԫ����˳����е�λ���ǣ�%d\n", pos);
            }
            else {
                printf("��Ԫ�ز���˳����У�\n");
            }
            break;
        case 4:
            printf("������Ҫ�����λ�ã�");
            scanf("%d", &pos);
            InsertElement(&L, pos); // ��ָ��λ�ò�����Ԫ��
            break;
        case 5:
            printf("������Ҫɾ����λ�ã�");
            scanf("%d", &pos);
            DeleteElement(&L, pos); // ɾ��ָ��λ�õ�Ԫ��
            break;
        case 6:
            printf("�������˳���\n");
            exit(0); // �˳�����
        default:
            printf("��������ȷ��ѡ�\n");
            break;
        }
    } while (1);
    return 0;
}