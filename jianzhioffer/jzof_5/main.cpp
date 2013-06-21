#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef struct node {
    int val;
    node* next;
}ListNode;

void print_list_reverse(ListNode* pHead) {
    if (pHead == NULL) return ;
    vector<ListNode*> nodes;
    ListNode* pNode = pHead;
    while (pNode != NULL) {
        nodes.push_back(pNode);
        pNode = pNode->next;
    }
    while (!nodes.empty()) {
        printf("%d", (nodes.back())->val);
        nodes.pop_back();
        if (!nodes.empty()) {
            printf(", ");
        } else {
            printf("\n");
        }
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
    print_list_reverse(*a);
    return 0;
}
