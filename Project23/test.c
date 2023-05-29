#define _CRT_SECURE_NO_WARNINGS 1
//1. 定义、初始化二叉搜索树。
#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构体
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// 初始化二叉树
struct node* init_tree() {
    return NULL;
}


//2. 创建一棵二叉搜索树。
// 向二叉搜索树中插入节点
struct node* insert_node(struct node* root, int value) {
    if (root == NULL) {
        // 如果根节点为空，则创建一个新节点作为根节点
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = value;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    if (value < root->data) {
        // 如果插入值小于根节点的值，则递归插入到左子树
        root->left = insert_node(root->left, value);
    }
    else if (value > root->data) {
        // 如果插入值大于根节点的值，则递归插入到右子树
        root->right = insert_node(root->right, value);
    }

    // 返回根节点
    return root;
}

// 创建二叉搜索树
struct node* create_tree() {
    struct node* root = init_tree();
    int values[] = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };
    int size = sizeof(values) / sizeof(int);
    for (int i = 0; i < size; i++) {
        root = insert_node(root, values[i]);
    }
    return root;
}


//3. 二叉搜索树查找、插入和删除。

// 查找二叉搜索树中是否存在某个值
int search_node(struct node* root, int value) {
    if (root == NULL) {
        // 如果根节点为空，则返回0
        return 0;
    }
    if (root->data == value) {
        // 如果根节点的值等于查找值，则返回1
        return 1;
    }
    if (value < root->data) {
        // 如果查找值小于根节点的值，则递归查找左子树
        return search_node(root->left, value);
    }
    else {
        // 如果查找值大于根节点的值，则递归查找右子树
        return search_node(root->right, value);
    }
}

// 向二叉搜索树中删除节点
struct node* delete_node(struct node* root, int value) {
    if (root == NULL) {
        // 如果根节点为空，则返回空指针
        return NULL;
    }
    if (value < root->data) {
        // 如果待删除的值小于根节点的值，则递归删除左子树中的节点
        root->left = delete_node(root->left, value);
    }
    else if (value > root->data) {
        // 如果待删除的值大于根节点的值，则递归删除右子树中的节点
        root->right = delete_node(root->right, value);
    }
    else {
        // 如果待删除的值等于根节点的值，则执行删除操作
        if (root->left == NULL && root->right == NULL) {
            // 如果根节点为叶子节点，则直接删除
            free(root);
            return NULL;
        }
        else if (root->left == NULL) {
            // 如果根节点只有右子树，则用右子树替换根节点
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            // 如果根节点只有左子树，则用左子树替换根节点
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        else {
            // 如果根节点有左子树和右子树，则找到右子树中的最小节点，用它替换根节点
            struct node* temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
    }
    return root;
}
