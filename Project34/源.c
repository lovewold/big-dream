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
        printf("栈已满，无法压入元素。\n");
        return;
    }
    stack->top++;
    stack->data[stack->top] = value;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("栈为空，无法弹出元素。\n");
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

    printf("转换结果为：");
    while (!isEmpty(&stack)) {
        int digit = pop(&stack);
        printf("%d", digit);
    }
    printf("\n");
}

int main() {
    int num, base;

    printf("请输入一个十进制数：");
    scanf("%d", &num);

    printf("请输入目标进制（2-16）：");
    scanf("%d", &base);

    if (base < 2 || base > 16) {
        printf("目标进制无效。\n");
        return 0;
    }

    convertToBase(num, base);

    return 0;
}
