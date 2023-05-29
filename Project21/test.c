#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构体
typedef struct TreeNode 
{
    int val; // 节点的值
    struct TreeNode* left; // 左子树
    struct TreeNode* right; // 右子树
} Node;

// 初始化一个节点
Node* create_node(int val)
{
    Node* node = (Node*)malloc(sizeof(Node)); // 为节点分配内存空间
    node->val = val; // 初始化节点值
    node->left = NULL; // 初始化左子树为空
    node->right = NULL; // 初始化右子树为空
    return node; // 返回节点
}

// 创建一棵二叉树
Node* create_binary_tree() 
{
    Node* root = create_node(1); // 根节点的值为1
    root->left = create_node(2); // 左子树节点的值为2
    root->right = create_node(3); // 右子树节点的值为3
    root->left->left = create_node(4); // 左子树的左子树节点的值为4
    root->left->right = create_node(5); // 左子树的右子树节点的值为5
    root->right->left = create_node(6); // 右子树的左子树节点的值为6
    root->right->right = create_node(7); // 右子树的右子树节点的值为7
    return root; // 返回根节点
}

// 先序遍历二叉树
void preorder_traversal(Node* root) 
{
    if (root == NULL) 
    {
        return; // 如果节点为空，直接返回
    }
    printf("%d ", root->val); // 先输出根节点的值
    preorder_traversal(root->left); // 递归遍历左子树
    preorder_traversal(root->right); // 递归遍历右子树
}

// 中序遍历二叉树
void inorder_traversal(Node* root) 
{
    if (root == NULL) 
    {
        return; // 如果节点为空，直接返回
    }
    inorder_traversal(root->left); // 递归遍历左子树
    printf("%d ", root->val); // 输出根节点的值
    inorder_traversal(root->right); // 递归遍历右子树
}

// 后序遍历二叉树
void postorder_traversal(Node* root) 
{
    if (root == NULL)
    {
        return; // 如果节点为空，直接返回
    }
    postorder_traversal(root->left); // 递归遍历左子树
    postorder_traversal(root->right); // 递归遍历右子树
    printf("%d ", root->val); // 输出根节点的值
}

// 层次遍历二叉树
void level_order_traversal(Node* root) 
{
    if (root == NULL) 
    {
        return; // 如果节点为空，直接返回
    }
    Node* queue[100]; // 定义一个队列，用于存储每层的节点
    int front = 0; // 定义队列的头指针
    int rear = 0; // 定义队列的尾指针
    queue[rear++] = root; // 将根节点入队
    while (front < rear) 
    { // 当队列不为空时，执行循环
        Node* current_node = queue[front++]; // 取出队首节点
        printf("%d ", current_node->val); // 输出节点的值
        if (current_node->left != NULL) 
        {
            queue[rear++] = current_node->left; // 如果左子树不为空，将左子树节点入队
        }
        if (current_node->right != NULL) 
        {
            queue[rear++] = current_node->right; // 如果右子树不为空，将右子树节点入队
        }
    }
}

// 主函数，用于测试上述函数的实现
int main() {
    Node* root = create_binary_tree(); // 创建一棵二叉树
    printf("先序遍历： ");
    preorder_traversal(root); // 先序遍历二叉树
    printf("\n");
    printf("中序遍历： ");
    inorder_traversal(root); // 中序遍历二叉树
    printf("\n");
    printf("后序遍历： ");
    postorder_traversal(root); // 后序遍历二叉树
    printf("\n");
    printf("层次遍历： ");
    level_order_traversal(root); // 层次遍历二叉树
    printf("\n");
    return 0; // 返回0表示程序正常结束
}
