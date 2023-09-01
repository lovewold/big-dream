#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

        // ���������ṹ��
        typedef struct TreeNode {
    char name[31]; // ��������
    int count; // ��������
    struct TreeNode* left; // ������ָ��
    struct TreeNode* right; // ������ָ��
} TreeNode;

// ����һ���µ�����㣬��ʼ�������ƺ���������������ָ��
TreeNode* newNode(char* name) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode)); // �����ڴ�ռ�
    strcpy(node->name, name);
    node->count = 1; // ��ʼ������Ϊ1
    node->left = node->right = NULL; // ��ʼ����������Ϊ��
    return node;
}

// ��һ���������Ʋ��뵽�����������У�����Ѵ��������������������򴴽��½��
void insert(TreeNode** root, char* name) {
    if (*root == NULL) { // ��������Ϊ�գ�˵���ǿ�����ֱ�Ӵ����½����Ϊ�����
        *root = newNode(name);
        return;
    }
    int cmp = strcmp(name, (*root)->name);
    if (cmp == 0) { // �����ȣ�˵���ҵ�����ͬ�����֣�����������
        (*root)->count++;
    }
    else if (cmp < 0) { // ���С�ڣ�˵��Ҫ������������ֵ������ڸ����֮ǰ���ݹ���뵽��������
        insert(&(*root)->left, name);
    }
    else { // ������ڣ�˵��Ҫ������������ֵ������ڸ����֮�󣬵ݹ���뵽��������
        insert(&(*root)->right, name);
    }
}

// ������������������������ÿ���������ƺͰٷֱ�
void inorder(TreeNode* root, int total) {
    if (root == NULL) return; // ���Ϊ�գ�ֱ�ӷ���
    inorder(root->left, total); // �ȱ���������
    printf("%s %.4f%%\n", root->name, root->count * 100.0 / total); // �����ǰ�������ƺͰٷֱȣ�������λС��
    inorder(root->right, total); // �ٱ���������
}

// �ͷŶ���������ռ�õ��ڴ�ռ�
void freeTree(TreeNode* root) {
    if (root == NULL) return; // ���Ϊ�գ�ֱ�ӷ���
    freeTree(root->left); // ���ͷ�������
    freeTree(root->right); // ���ͷ�������
    free(root); // ����ͷŵ�ǰ���
}

int main() {
    int N; // ��������
    char name[31]; // ��������
    TreeNode* root = NULL; // �����������ĸ����

    printf("����������������\n");
    scanf("%d", &N);

    printf("������ÿ�������������ƣ�\n");
    for (int i = 0; i < N; i++) { // ѭ��N�Σ�����ÿ�������������ƣ������뵽������������
        scanf("%s", name);
        insert(&root, name);
    }

    printf("���ÿ�������������Ƽ�����ռ�����İٷֱȣ�\n"); // �����ʾ
    inorder(root, N); // ���������������������������

    freeTree(root); // �ͷŶ���������ռ�õ��ڴ�ռ�

    return 0;
}

