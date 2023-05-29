#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100  // 定义顺序表的最大长度

// 定义图书记录结构体类型
typedef struct BookRecord {
    int id;            // 登录号
    char name[20];     // 书名
    char author[20];   // 作者
    char publisher[20];// 出版社
    float price;       // 价格
}BookRecord;

// 定义顺序表结构体类型
typedef struct SeqList {
    BookRecord data[MAXSIZE]; // 存储顺序表元素的数组
    int length;               // 当前顺序表的长度
}SeqList;

// 初始化顺序表
void InitList(SeqList* L) {
    L->length = 0;  // 将顺序表长度初始化为 0
}

// 输入顺序表元素
void InputElement(SeqList* L) {
    BookRecord book;
    printf("请输入登录号: ");
    scanf("%d", &book.id);
    printf("请输入书名: ");
    scanf("%s", book.name);
    printf("请输入作者: ");
    scanf("%s", book.author);
    printf("请输入出版社: ");
    scanf("%s", book.publisher);
    printf("请输入价格: ");
    scanf("%f", &book.price);
    L->data[L->length] = book;
    L->length++;   // 将顺序表长度加 1
}

// 输出顺序表元素
void PrintList(SeqList L) {
    printf("序号\t登录号\t\t书名\t\t作者\t\t出版社\t\t价格\n");
    for (int i = 0; i < L.length; i++) {
        printf("%d\t%d\t\t%s\t\t%s\t\t%s\t\t%.2f\n", i + 1, L.data[i].id, L.data[i].name, L.data[i].author, L.data[i].publisher, L.data[i].price);
    }
}

// 查找元素的位置
int LocateElement(SeqList L, int id) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i].id == id) {
            return i + 1;  // 找到元素，返回它在顺序表中的位置（从 1 开始）
        }
    }
    return 0;  // 没有找到元素，返回 0
}

// 在指定位置插入新元素
void InsertElement(SeqList* L, int pos) {
    if (pos < 1 || pos > L->length + 1) {  // 判断插入位置是否合法
        printf("插入位置非法！\n");
        return;
    }
    BookRecord book;
    printf("请输入登录号: ");
    scanf("%d", &book.id);
    printf("请输入书名: ");
    scanf("%s", book.name);
    printf("请输入作者: ");
    scanf("%s", book.author);
    printf("请输入出版社: ");
    scanf("%s", book.publisher);
    printf("请输入价格: ");
    scanf("%f", &book.price);
    // 在指定位置插入新元素
    for (int i = L->length; i >= pos; i--) {
        L->data[i] = L->data[i - 1];
    }
    L->data[pos - 1] = book;
    L->length++;  // 将顺序表长度加 1
    printf("插入成功！\n");
}

// 删除指定位置的元素
void DeleteElement(SeqList* L, int pos) {
    if (pos < 1 || pos > L->length) { // 判断删除位置是否合法
        printf("删除位置非法！\n");
        return;
    }
    // 在指定位置删除元素
    for (int i = pos - 1; i < L->length - 1; i++) {
        L->data[i] = L->data[i + 1];
    }
    L->length--; // 将顺序表长度减 1
    printf("删除成功！\n");
}

// 主程序
int main() {
    SeqList L;
    int choice, pos, id;
    InitList(&L); // 初始化顺序表
    do {
        printf("请选择要执行的操作：\n");
        printf("1. 输入\n");
        printf("2. 输出\n");
        printf("3. 查找\n");
        printf("4. 插入\n");
        printf("5. 删除\n");
        printf("6. 退出程序\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            InputElement(&L); // 输入顺序表元素
            break;
        case 2:
            PrintList(L); // 输出顺序表元素
            break;
        case 3:
            printf("请输入要查找的登录号：");
            scanf("%d", &id);
            pos = LocateElement(L, id); // 查找元素的位置
            if (pos) {
                printf("该元素在顺序表中的位置是：%d\n", pos);
            }
            else {
                printf("该元素不在顺序表中！\n");
            }
            break;
        case 4:
            printf("请输入要插入的位置：");
            scanf("%d", &pos);
            InsertElement(&L, pos); // 在指定位置插入新元素
            break;
        case 5:
            printf("请输入要删除的位置：");
            scanf("%d", &pos);
            DeleteElement(&L, pos); // 删除指定位置的元素
            break;
        case 6:
            printf("程序已退出！\n");
            exit(0); // 退出程序
        default:
            printf("请输入正确的选项！\n");
            break;
        }
    } while (1);
    return 0;
}