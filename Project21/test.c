#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ��
typedef struct TreeNode 
{
    int val; // �ڵ��ֵ
    struct TreeNode* left; // ������
    struct TreeNode* right; // ������
} Node;

// ��ʼ��һ���ڵ�
Node* create_node(int val)
{
    Node* node = (Node*)malloc(sizeof(Node)); // Ϊ�ڵ�����ڴ�ռ�
    node->val = val; // ��ʼ���ڵ�ֵ
    node->left = NULL; // ��ʼ��������Ϊ��
    node->right = NULL; // ��ʼ��������Ϊ��
    return node; // ���ؽڵ�
}

// ����һ�ö�����
Node* create_binary_tree() 
{
    Node* root = create_node(1); // ���ڵ��ֵΪ1
    root->left = create_node(2); // �������ڵ��ֵΪ2
    root->right = create_node(3); // �������ڵ��ֵΪ3
    root->left->left = create_node(4); // ���������������ڵ��ֵΪ4
    root->left->right = create_node(5); // ���������������ڵ��ֵΪ5
    root->right->left = create_node(6); // ���������������ڵ��ֵΪ6
    root->right->right = create_node(7); // ���������������ڵ��ֵΪ7
    return root; // ���ظ��ڵ�
}

// �������������
void preorder_traversal(Node* root) 
{
    if (root == NULL) 
    {
        return; // ����ڵ�Ϊ�գ�ֱ�ӷ���
    }
    printf("%d ", root->val); // ��������ڵ��ֵ
    preorder_traversal(root->left); // �ݹ����������
    preorder_traversal(root->right); // �ݹ����������
}

// �������������
void inorder_traversal(Node* root) 
{
    if (root == NULL) 
    {
        return; // ����ڵ�Ϊ�գ�ֱ�ӷ���
    }
    inorder_traversal(root->left); // �ݹ����������
    printf("%d ", root->val); // ������ڵ��ֵ
    inorder_traversal(root->right); // �ݹ����������
}

// �������������
void postorder_traversal(Node* root) 
{
    if (root == NULL)
    {
        return; // ����ڵ�Ϊ�գ�ֱ�ӷ���
    }
    postorder_traversal(root->left); // �ݹ����������
    postorder_traversal(root->right); // �ݹ����������
    printf("%d ", root->val); // ������ڵ��ֵ
}

// ��α���������
void level_order_traversal(Node* root) 
{
    if (root == NULL) 
    {
        return; // ����ڵ�Ϊ�գ�ֱ�ӷ���
    }
    Node* queue[100]; // ����һ�����У����ڴ洢ÿ��Ľڵ�
    int front = 0; // ������е�ͷָ��
    int rear = 0; // ������е�βָ��
    queue[rear++] = root; // �����ڵ����
    while (front < rear) 
    { // �����в�Ϊ��ʱ��ִ��ѭ��
        Node* current_node = queue[front++]; // ȡ�����׽ڵ�
        printf("%d ", current_node->val); // ����ڵ��ֵ
        if (current_node->left != NULL) 
        {
            queue[rear++] = current_node->left; // �����������Ϊ�գ����������ڵ����
        }
        if (current_node->right != NULL) 
        {
            queue[rear++] = current_node->right; // �����������Ϊ�գ����������ڵ����
        }
    }
}

// �����������ڲ�������������ʵ��
int main() {
    Node* root = create_binary_tree(); // ����һ�ö�����
    printf("��������� ");
    preorder_traversal(root); // �������������
    printf("\n");
    printf("��������� ");
    inorder_traversal(root); // �������������
    printf("\n");
    printf("��������� ");
    postorder_traversal(root); // �������������
    printf("\n");
    printf("��α����� ");
    level_order_traversal(root); // ��α���������
    printf("\n");
    return 0; // ����0��ʾ������������
}
