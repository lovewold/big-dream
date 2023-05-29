#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 定义二叉搜索树的节点结构
typedef struct node 
{
    int key; // 关键字
    struct node* left; // 左子节点
    struct node* right; // 右子节点
} node;

// 初始化一个空的二叉搜索树
node* init_tree()
{
    return NULL;
}

// 创建一个新的节点
node* create_node(int key)
{
    node* new_node = (node*)malloc(sizeof(node)); // 分配内存空间
    if (new_node == NULL) 
    { // 判断内存分配是否成功
        printf("Memory allocation failed.\n");
        exit(1);
    }
    new_node->key = key; // 设置关键字
    new_node->left = NULL; // 设置左子节点为空
    new_node->right = NULL; // 设置右子节点为空
    return new_node;
}

// 在二叉搜索树中查找一个节点，如果找到返回该节点的指针，如果没找到返回NULL
node* search(node* root, int key) 
{
    if (root == NULL) 
    { // 如果树为空，返回NULL
        return NULL;
    }
    if (key == root->key) 
    { // 如果关键字等于根节点的关键字，返回根节点的指针
        return root;
    }
    if (key < root->key) 
    { // 如果关键字小于根节点的关键字，递归查找左子树
        return search(root->left, key);
    }
    if (key > root->key) 
    { // 如果关键字大于根节点的关键字，递归查找右子树
        return search(root->right, key);
    }
}

// 在二叉搜索树中插入一个节点，如果插入成功返回1，如果插入失败返回0
int insert(node** root, int key) 
{
    if (*root == NULL) 
    { // 如果树为空，创建一个新的节点作为根节点，并返回1
        *root = create_node(key);
        return 1;
    }
    if (key == (*root)->key)
    { // 如果关键字等于根节点的关键字，插入失败，返回0
        return 0;
    }
    if (key < (*root)->key) 
    { // 如果关键字小于根节点的关键字，递归插入左子树，并返回结果
        return insert(&(*root)->left, key);
    }
    if (key > (*root)->key) 
    { // 如果关键字大于根节点的关键字，递归插入右子树，并返回结果
        return insert(&(*root)->right, key);
    }
}

// 在二叉搜索树中删除一个节点，如果删除成功返回1，如果删除失败返回0
int delete(node** root, int key) 
{
    if (*root == NULL) 
    { // 如果树为空，删除失败，返回0
        return 0;
    }
    if (key < (*root)->key) 
    { // 如果关键字小于根节点的关键字，递归删除左子树，并返回结果
        return delete(&(*root)->left, key);
    }
    if (key > (*root)->key) 
    { // 如果关键字大于根节点的关键字，递归删除右子树，并返回结果
        return delete(&(*root)->right, key);
    }
    if (key == (*root)->key) 
    { // 如果关键字等于根节点的关键字，删除该节点，并返回1
        node* temp = NULL; // 定义一个临时指针用于保存被删除节点或者替换节点
        if ((*root)->left == NULL && (*root)->right == NULL) 
        { // 如果该节点没有子节点，直接释放该节点的内存空间，并将其父节点指向NULL
            free(*root);
            *root = NULL;
        }
        else if ((*root)->left == NULL) 
        { // 如果该节点只有右子节点，将其右子节点替换该节点，并释放该节点的内存空间
            temp = *root;
            *root = (*root)->right;
            free(temp);
        }
        else if ((*root)->right == NULL) 
        { // 如果该节点只有左子节点，将其左子节点替换该节点，并释放该节点的内存空间
            temp = *root;
            *root = (*root)->left;
            free(temp);
        }
        else 
        { // 如果该节点有两个子节点，找到右子树中最小的节点来替换该节点，并删除右子树中最小的节点
            temp = (*root)->right; // 从右子树开始查找
            while (temp->left != NULL) 
            { // 循环找到右子树中最小的节点
                temp = temp->left;
            }
            (*root)->key = temp->key; // 将最小的节点的关键字复制到当前节点
            delete(&(*root)->right, temp->key); // 删除右子树中最小的节点
        }
        return 1;
    }
}

// 中序遍历二叉搜索树，并打印每个节点的关键字
void inorder(node* root) 
{
    if (root == NULL)
    { // 如果树为空，直接返回
        return;
    }
    inorder(root->left); // 递归遍历左子树
    printf("%d ", root->key); // 打印当前节点的关键字
    inorder(root->right); // 递归遍历右子树
}

// 主函数，测试二叉搜索树的功能
int main() 
{
    node* tree = init_tree(); // 初始化一个空的二叉搜索树
    int data[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // 定义一个数组用于存储插入的数据，这里是月份
    int n = sizeof(data) / sizeof(int); // 计算数组的长度
    int i; // 定义一个循环变量

    for (i = 0; i < n; i++) 
    { // 循环插入数组中的数据到二叉搜索树中
        if (insert(&tree, data[i])) 
        { // 如果插入成功，打印插入的数据和当前树的中序遍历结果
            printf("插入 %d 成功.\n", data[i]);
            printf("中序遍历结果: ");
            inorder(tree);
            printf("\n");
        }
        else 
        { // 如果插入失败，打印插入失败的信息
            printf("插入 %d 失败.\n", data[i]);
        }
    }

    int delete_data[] = { 3, 5, 7 }; // 定义一个数组用于存储要删除的数据
    int m = sizeof(delete_data) / sizeof(int); // 计算数组的长度
    printf("指定删除3，5，7\n");
    for (i = 0; i < m; i++)
    { // 循环删除数组中的数据从二叉搜索树中
        if (delete(&tree, delete_data[i]))
        { // 如果删除成功，打印删除的数据和当前树的中序遍历结果
            printf("删除 %d 成功.\n", delete_data[i]);
            printf("中序遍历结果: ");
            inorder(tree);
            printf("\n");
        }
        else
        { // 如果删除失败，打印删除失败的信息
            printf("删除 %d 失败.\n", delete_data[i]);
        }
    }

    return 0;
}
