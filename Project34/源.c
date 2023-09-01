#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack* stack) {
    stack->top = -1;
}

bool isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("ջ�������޷�ѹ��Ԫ�ء�\n");
        return;
    }
    stack->top++;
    stack->data[stack->top] = value;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("ջΪ�գ��޷�����Ԫ�ء�\n");
        return -1;
    }
    int value = stack->data[stack->top];
    stack->top--;
    return value;
}

void convertToBase(int num, int base) {
    Stack stack;
    initialize(&stack);

    while (num > 0) {
        int remainder = num % base;
        push(&stack, remainder);
        num /= base;
    }

    printf("ת�����Ϊ��");
    while (!isEmpty(&stack)) {
        int digit = pop(&stack);
        printf("%d", digit);
    }
    printf("\n");
}

int main() {
    int num, base;

    printf("������һ��ʮ��������");
    scanf("%d", &num);

    printf("������Ŀ����ƣ�2-16����");
    scanf("%d", &base);

    if (base < 2 || base > 16) {
        printf("Ŀ�������Ч��\n");
        return 0;
    }

    convertToBase(num, base);

    return 0;
}
