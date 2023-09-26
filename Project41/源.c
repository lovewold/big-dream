#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
/**
 * Definition for singly-linked list.

 * };
 */

struct ListNode
{
    int val;
    struct ListNode* next;
};

//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//    struct ListNode* L = (struct ListNode*)malloc(sizeof(struct ListNode));
//    L->next = head;
//    struct ListNode* P = L;
//    while (L->next&&L->next->next)
//    {
//        if (L->next->val == val)
//        {
//
//            L->next = L->next->next->next;
//        }
//        else
//        {
//            L->next = L->next->next;
//        }
//    }
//    return P->next;
//}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* star[1000] = { NULL };
    int i = 0;
    while (head)
    {
        if (head->val != val)
        {
            star[i] = head;
            i++;
        }
        else
        {
            head = head->next;
        }
    }

    return star;
}
int main()
{
    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n7 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n1->val = 1;
    n2->val = 2;
    n3->val = 6;
    n4->val = 3;
    n5->val = 4;
    n6->val = 5;
    n7->val = 6;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = NULL;
    removeElements(n1, 6);
    return 0;
}