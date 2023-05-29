#define _CRT_SECURE_NO_WARNINGS 1
//1. ���塢��ʼ��������������
#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ��
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// ��ʼ��������
struct node* init_tree() {
    return NULL;
}


//2. ����һ�ö�����������
// ������������в���ڵ�
struct node* insert_node(struct node* root, int value) {
    if (root == NULL) {
        // ������ڵ�Ϊ�գ��򴴽�һ���½ڵ���Ϊ���ڵ�
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = value;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    if (value < root->data) {
        // �������ֵС�ڸ��ڵ��ֵ����ݹ���뵽������
        root->left = insert_node(root->left, value);
    }
    else if (value > root->data) {
        // �������ֵ���ڸ��ڵ��ֵ����ݹ���뵽������
        root->right = insert_node(root->right, value);
    }

    // ���ظ��ڵ�
    return root;
}

// ��������������
struct node* create_tree() {
    struct node* root = init_tree();
    int values[] = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };
    int size = sizeof(values) / sizeof(int);
    for (int i = 0; i < size; i++) {
        root = insert_node(root, values[i]);
    }
    return root;
}


//3. �������������ҡ������ɾ����

// ���Ҷ������������Ƿ����ĳ��ֵ
int search_node(struct node* root, int value) {
    if (root == NULL) {
        // ������ڵ�Ϊ�գ��򷵻�0
        return 0;
    }
    if (root->data == value) {
        // ������ڵ��ֵ���ڲ���ֵ���򷵻�1
        return 1;
    }
    if (value < root->data) {
        // �������ֵС�ڸ��ڵ��ֵ����ݹ����������
        return search_node(root->left, value);
    }
    else {
        // �������ֵ���ڸ��ڵ��ֵ����ݹ����������
        return search_node(root->right, value);
    }
}

// �������������ɾ���ڵ�
struct node* delete_node(struct node* root, int value) {
    if (root == NULL) {
        // ������ڵ�Ϊ�գ��򷵻ؿ�ָ��
        return NULL;
    }
    if (value < root->data) {
        // �����ɾ����ֵС�ڸ��ڵ��ֵ����ݹ�ɾ���������еĽڵ�
        root->left = delete_node(root->left, value);
    }
    else if (value > root->data) {
        // �����ɾ����ֵ���ڸ��ڵ��ֵ����ݹ�ɾ���������еĽڵ�
        root->right = delete_node(root->right, value);
    }
    else {
        // �����ɾ����ֵ���ڸ��ڵ��ֵ����ִ��ɾ������
        if (root->left == NULL && root->right == NULL) {
            // ������ڵ�ΪҶ�ӽڵ㣬��ֱ��ɾ��
            free(root);
            return NULL;
        }
        else if (root->left == NULL) {
            // ������ڵ�ֻ���������������������滻���ڵ�
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            // ������ڵ�ֻ���������������������滻���ڵ�
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        else {
            // ������ڵ����������������������ҵ��������е���С�ڵ㣬�����滻���ڵ�
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
