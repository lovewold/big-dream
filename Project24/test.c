#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// ��������������Ľڵ�ṹ
typedef struct node 
{
    int key; // �ؼ���
    struct node* left; // ���ӽڵ�
    struct node* right; // ���ӽڵ�
} node;

// ��ʼ��һ���յĶ���������
node* init_tree()
{
    return NULL;
}

// ����һ���µĽڵ�
node* create_node(int key)
{
    node* new_node = (node*)malloc(sizeof(node)); // �����ڴ�ռ�
    if (new_node == NULL) 
    { // �ж��ڴ�����Ƿ�ɹ�
        printf("Memory allocation failed.\n");
        exit(1);
    }
    new_node->key = key; // ���ùؼ���
    new_node->left = NULL; // �������ӽڵ�Ϊ��
    new_node->right = NULL; // �������ӽڵ�Ϊ��
    return new_node;
}

// �ڶ����������в���һ���ڵ㣬����ҵ����ظýڵ��ָ�룬���û�ҵ�����NULL
node* search(node* root, int key) 
{
    if (root == NULL) 
    { // �����Ϊ�գ�����NULL
        return NULL;
    }
    if (key == root->key) 
    { // ����ؼ��ֵ��ڸ��ڵ�Ĺؼ��֣����ظ��ڵ��ָ��
        return root;
    }
    if (key < root->key) 
    { // ����ؼ���С�ڸ��ڵ�Ĺؼ��֣��ݹ����������
        return search(root->left, key);
    }
    if (key > root->key) 
    { // ����ؼ��ִ��ڸ��ڵ�Ĺؼ��֣��ݹ����������
        return search(root->right, key);
    }
}

// �ڶ����������в���һ���ڵ㣬�������ɹ�����1���������ʧ�ܷ���0
int insert(node** root, int key) 
{
    if (*root == NULL) 
    { // �����Ϊ�գ�����һ���µĽڵ���Ϊ���ڵ㣬������1
        *root = create_node(key);
        return 1;
    }
    if (key == (*root)->key)
    { // ����ؼ��ֵ��ڸ��ڵ�Ĺؼ��֣�����ʧ�ܣ�����0
        return 0;
    }
    if (key < (*root)->key) 
    { // ����ؼ���С�ڸ��ڵ�Ĺؼ��֣��ݹ�����������������ؽ��
        return insert(&(*root)->left, key);
    }
    if (key > (*root)->key) 
    { // ����ؼ��ִ��ڸ��ڵ�Ĺؼ��֣��ݹ�����������������ؽ��
        return insert(&(*root)->right, key);
    }
}

// �ڶ�����������ɾ��һ���ڵ㣬���ɾ���ɹ�����1�����ɾ��ʧ�ܷ���0
int delete(node** root, int key) 
{
    if (*root == NULL) 
    { // �����Ϊ�գ�ɾ��ʧ�ܣ�����0
        return 0;
    }
    if (key < (*root)->key) 
    { // ����ؼ���С�ڸ��ڵ�Ĺؼ��֣��ݹ�ɾ���������������ؽ��
        return delete(&(*root)->left, key);
    }
    if (key > (*root)->key) 
    { // ����ؼ��ִ��ڸ��ڵ�Ĺؼ��֣��ݹ�ɾ���������������ؽ��
        return delete(&(*root)->right, key);
    }
    if (key == (*root)->key) 
    { // ����ؼ��ֵ��ڸ��ڵ�Ĺؼ��֣�ɾ���ýڵ㣬������1
        node* temp = NULL; // ����һ����ʱָ�����ڱ��汻ɾ���ڵ�����滻�ڵ�
        if ((*root)->left == NULL && (*root)->right == NULL) 
        { // ����ýڵ�û���ӽڵ㣬ֱ���ͷŸýڵ���ڴ�ռ䣬�����丸�ڵ�ָ��NULL
            free(*root);
            *root = NULL;
        }
        else if ((*root)->left == NULL) 
        { // ����ýڵ�ֻ�����ӽڵ㣬�������ӽڵ��滻�ýڵ㣬���ͷŸýڵ���ڴ�ռ�
            temp = *root;
            *root = (*root)->right;
            free(temp);
        }
        else if ((*root)->right == NULL) 
        { // ����ýڵ�ֻ�����ӽڵ㣬�������ӽڵ��滻�ýڵ㣬���ͷŸýڵ���ڴ�ռ�
            temp = *root;
            *root = (*root)->left;
            free(temp);
        }
        else 
        { // ����ýڵ��������ӽڵ㣬�ҵ�����������С�Ľڵ����滻�ýڵ㣬��ɾ������������С�Ľڵ�
            temp = (*root)->right; // ����������ʼ����
            while (temp->left != NULL) 
            { // ѭ���ҵ�����������С�Ľڵ�
                temp = temp->left;
            }
            (*root)->key = temp->key; // ����С�Ľڵ�Ĺؼ��ָ��Ƶ���ǰ�ڵ�
            delete(&(*root)->right, temp->key); // ɾ������������С�Ľڵ�
        }
        return 1;
    }
}

// �����������������������ӡÿ���ڵ�Ĺؼ���
void inorder(node* root) 
{
    if (root == NULL)
    { // �����Ϊ�գ�ֱ�ӷ���
        return;
    }
    inorder(root->left); // �ݹ����������
    printf("%d ", root->key); // ��ӡ��ǰ�ڵ�Ĺؼ���
    inorder(root->right); // �ݹ����������
}

// �����������Զ����������Ĺ���
int main() 
{
    node* tree = init_tree(); // ��ʼ��һ���յĶ���������
    int data[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // ����һ���������ڴ洢��������ݣ��������·�
    int n = sizeof(data) / sizeof(int); // ��������ĳ���
    int i; // ����һ��ѭ������

    for (i = 0; i < n; i++) 
    { // ѭ�����������е����ݵ�������������
        if (insert(&tree, data[i])) 
        { // �������ɹ�����ӡ��������ݺ͵�ǰ��������������
            printf("���� %d �ɹ�.\n", data[i]);
            printf("����������: ");
            inorder(tree);
            printf("\n");
        }
        else 
        { // �������ʧ�ܣ���ӡ����ʧ�ܵ���Ϣ
            printf("���� %d ʧ��.\n", data[i]);
        }
    }

    int delete_data[] = { 3, 5, 7 }; // ����һ���������ڴ洢Ҫɾ��������
    int m = sizeof(delete_data) / sizeof(int); // ��������ĳ���
    printf("ָ��ɾ��3��5��7\n");
    for (i = 0; i < m; i++)
    { // ѭ��ɾ�������е����ݴӶ�����������
        if (delete(&tree, delete_data[i]))
        { // ���ɾ���ɹ�����ӡɾ�������ݺ͵�ǰ��������������
            printf("ɾ�� %d �ɹ�.\n", delete_data[i]);
            printf("����������: ");
            inorder(tree);
            printf("\n");
        }
        else
        { // ���ɾ��ʧ�ܣ���ӡɾ��ʧ�ܵ���Ϣ
            printf("ɾ�� %d ʧ��.\n", delete_data[i]);
        }
    }

    return 0;
}
