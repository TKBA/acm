#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef struct node {
    int val;
    node* next;
}ListNode;

void print_list_reverse(ListNode* pHead, bool first = true) {
    if (pHead == NULL) return ;
    print_list_reverse(pHead->next, false);
    printf("%d", pHead->val);
    if (first) {
        printf("\n");
    } else {
        printf(", ");
    }
}

void add_to_tail(ListNode** pHead, int val) {
    if (pHead == NULL) return ;
    ListNode* pNew = new ListNode();
    pNew->val = val;
    pNew->next = NULL;

    if (*pHead == NULL) {
        *pHead = pNew;
    } else {
        ListNode* pNode = *pHead;
        while (pNode->next != NULL) {
            pNode = pNode->next;
        }
        pNode->next = pNew;
    }
}

void print(ListNode** pHead) {
    if (pHead == NULL || *pHead == NULL) return ;
    ListNode* pNode = *pHead;
    while (pNode->next != NULL) {
        printf("%d, ", pNode->val);
        pNode = pNode->next;
    }
    printf("%d\n", pNode->val);
}

int main()
{
    ListNode* p = NULL;
    ListNode** a = &p;
    for (int i = 1; i <= 10; i++) {
        add_to_tail(a, i);
    }

    print(a);
    print_list_reverse(*a, true);
    return 0;
}
