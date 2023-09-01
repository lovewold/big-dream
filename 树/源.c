#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

        // 定义树结点结构体
        typedef struct TreeNode {
    char name[31]; // 树种名称
    int count; // 树种数量
    struct TreeNode* left; // 左子树指针
    struct TreeNode* right; // 右子树指针
} TreeNode;

// 创建一个新的树结点，初始化其名称和数量，并返回其指针
TreeNode* newNode(char* name) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode)); // 分配内存空间
    strcpy(node->name, name);
    node->count = 1; // 初始化数量为1
    node->left = node->right = NULL; // 初始化左右子树为空
    return node;
}

// 将一个树种名称插入到二叉搜索树中，如果已存在则增加其数量，否则创建新结点
void insert(TreeNode** root, char* name) {
    if (*root == NULL) { // 如果根结点为空，说明是空树，直接创建新结点作为根结点
        *root = newNode(name);
        return;
    }
    int cmp = strcmp(name, (*root)->name);
    if (cmp == 0) { // 如果相等，说明找到了相同的树种，增加其数量
        (*root)->count++;
    }
    else if (cmp < 0) { // 如果小于，说明要插入的名称在字典序上在根结点之前，递归插入到左子树中
        insert(&(*root)->left, name);
    }
    else { // 如果大于，说明要插入的名称在字典序上在根结点之后，递归插入到右子树中
        insert(&(*root)->right, name);
    }
}

// 中序遍历二叉搜索树，并输出每种树的名称和百分比
void inorder(TreeNode* root, int total) {
    if (root == NULL) return; // 如果为空，直接返回
    inorder(root->left, total); // 先遍历左子树
    printf("%s %.4f%%\n", root->name, root->count * 100.0 / total); // 输出当前结点的名称和百分比，保留四位小数
    inorder(root->right, total); // 再遍历右子树
}

// 释放二叉搜索树占用的内存空间
void freeTree(TreeNode* root) {
    if (root == NULL) return; // 如果为空，直接返回
    freeTree(root->left); // 先释放左子树
    freeTree(root->right); // 再释放右子树
    free(root); // 最后释放当前结点
}

int main() {
    int N; // 树的数量
    char name[31]; // 树种名称
    TreeNode* root = NULL; // 二叉搜索树的根结点

    printf("请输入树的数量：\n");
    scanf("%d", &N);

    printf("请输入每棵树的种类名称：\n");
    for (int i = 0; i < N; i++) { // 循环N次，输入每棵树的种类名称，并插入到二叉搜索树中
        scanf("%s", name);
        insert(&root, name);
    }

    printf("输出每种树的种类名称及其所占总数的百分比：\n"); // 输出提示
    inorder(root, N); // 中序遍历二叉搜索树，并输出结果

    freeTree(root); // 释放二叉搜索树占用的内存空间

    return 0;
}

