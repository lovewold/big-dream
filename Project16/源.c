#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX_SIZE 100
//
//typedef struct {
//    int data[MAX_SIZE];
//    int len;
//} SeqList;
//
//void build_list(SeqList* L) {
//    printf("������˳���ĳ���: ");
//    scanf("%d", &(L->len));
//    printf("������ %d ����������: ", L->len);
//    for (int i = 0; i < L->len; i++) {
//        scanf("%d", &(L->data[i]));
//    }
//}
//
//void insert_list(SeqList* L, int num) {
//    if (L->len == MAX_SIZE)
//    {
//        printf("����ʧ��\n");
//    }
//    int j = 0;
//    for (j = 0; j < L->len - 1; j++)
//    {
//        if (L->data[j] == num)
//        {
//            printf("�ظ�����,����ʧ��\n");
//        }
//    }
//    int i = L->len - 1;
//    while (i >= 0 && L->data[i] > num) {
//        L->data[i + 1] = L->data[i];
//        i--;
//    }
//    L->data[i + 1] = num;
//    L->len++;
//}
//
//void delete_list(SeqList* L, int num) {
//    int i = 0;
//    for(i = 0; i < L->len - 1; i++)
//    {
//        if (L->data[i] == num)
//        {
//            int j = i;
//            for (j = i; j < L->len - 1; j++)
//            {
//                L->data[j] = L->data[j + 1];
//
//            }
//            L->len--;
//        }
//    }
//    if (i = L->len - 1)
//    {
//        printf("ɾ��ʧ��\n");
//    }
//    
//}
//void insert_num(SeqList* L) {
//    int num;
//    printf("������Ҫ���������: ");
//    scanf("%d", &num);
//    insert_list(L, num);
//}
//
//void print_list(SeqList L) {
//    printf("�µ�������������Ϊ: ");
//    for (int i = 0; i < L.len; i++) {
//        printf("%d ", L.data[i]);
//    }
//}
//void delete_my(SeqList* L)
//{
//        int num;
//        printf("������Ҫɾ��������: ");
//        scanf("%d", &num);
//        delete_list(L, num);
//  
//}
//void menu()
//{
//    printf("********************************\n");
//    printf("*********   1. ����     ********\n");
//    printf("*********   2. ɾ��     ********\n");
//    printf("********************************\n");
//
//}
//int main() {
//    SeqList L;
//    build_list(&L);
//    menu();
//    int a = 0;
//    scanf("%d", &a);
//   
//        switch (a)
//        {
//        case 1:
//            insert_num(&L);
//            break;
//        case 2:
//            delete_my(&L);
//            break;
//        default:
//            printf("�������");
//        }
//    print_list(L);
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100
#define NAMESIZE 20

typedef struct {
    int id;
    char name[NAMESIZE];
    float score;
} Student;

typedef struct {
    Student data[MAXSIZE];
    int length;
} SeqList;

void InitList(SeqList* L) {
    L->length = 0;
}

void InputList(SeqList* L, Student s) {
    if (L->length == MAXSIZE) {
        printf("Error: List is full!\n");
        return;
    }
    L->data[L->length] = s;
    L->length++;
}

void PrintList(SeqList L) {
    printf("ID\tName\tScore\n");
    for (int i = 0; i < L.length; i++) {
        printf("%d\t%s\t%.2f\n", L.data[i].id, L.data[i].name, L.data[i].score);
    }
}

int LocateElement(SeqList L, int id) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i].id == id) {
            return i + 1;
        }
    }
    return -1;
}

int InsertElement(SeqList* L, int pos, Student s) {
    if (L->length == MAXSIZE) {
        printf("Error: List is full!\n");
        return 0;
    }
    if (pos < 1 || pos > L->length + 1) {
        printf("Error: Index out of range!\n");
        return 0;
    }
    for (int i = L->length; i >= pos; i--) {
        L->data[i] = L->data[i - 1];
    }
    L->data[pos - 1] = s;
    L->length++;
    return 1;
}

int DeleteElement(SeqList* L, int pos) {
    if (pos < 1 || pos > L->length) {
        printf("Error: Index out of range!\n");
        return 0;
    }
    for (int i = pos; i < L->length; i++) {
        L->data[i - 1] = L->data[i];
    }
    L->length--;
    return 1;
}

int main()
{
    SeqList L;
    InitList(&L);

    int n;
    printf("������Ҫ���뼸��ѧ����¼��\n");
    scanf("%d", &n);

    Student element;
    for (int i = 0; i < n; i++) {
        printf("�������%d��ͬѧ��ѧ�ţ�\n", i + 1);
        scanf("%d", &element.id);

        printf("�������%d��ͬѧ��������\n", i + 1);
        scanf("%s", element.name);

        printf("�������%d��ͬѧ�ĳɼ���\n", i + 1);
        scanf("%f", &element.score);

        InputList(&L, element); // pass the address of L and the element to InputList
    }

    // ���˳���Ԫ����Ϣ
    PrintList(L); // pass L directly to PrintList

      // ����ѧ����¼
    printf("�����������ѧ����Ϣ��\n");
    scanf("%s",&element.id);
    int p = LocateElement(L, &element); // pass L and the element to LocateElement
    if (p == -1) {
        printf("��ѧ����¼�����ڣ�\n");
    }
    else {
        printf("��ѧ����¼��˳����е�λ���ǣ�%d\n", p + 1);
    }

    // ����ѧ����¼
    int pos;
    printf("������Ҫ�ڸ�˳������ĸ�λ�ò�����Ԫ�أ�\n");
    scanf("%d", &pos);
    printf("�������ͬѧ��ѧ�ţ�\n");
    scanf("%s", &element.id);
    printf("�������ͬѧ��������\n");
    scanf("%s", &element.name);
    printf("�������ͬѧ�ĳɼ���\n");
    scanf("%f", &element.score);
    InsertElement(&L, pos - 1, element); // pass the address of L, the position and the element to InsertElement

    // ɾ��ѧ����¼
    int q;
    printf("������Ҫɾ����ѧ����¼λ�ã�\n");
    scanf("%d", &q);
    DeleteElement(&L, q - 1); // pass the address of L and the position to DeleteElement
    PrintList(L);

    printf("��������˳�\n");
    getchar();
    getchar();
}

