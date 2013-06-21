#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
/// 深入理解指针

struct ListNode {
    int m_nValue;
    ListNode* m_pNext;
};

void AddToTail(ListNode** pHead, int value) {
    ListNode* pNew = new ListNode();
puts("apply secuss!");

    pNew->m_nValue = value;
    pNew->m_pNext = NULL;

    if (*pHead == NULL) {
puts("*pHead = 0");

        *pHead = pNew;
puts("has a head");
        /// printf("pHead = %d\n", *pHead);
        /// printf("pHead->value = %d\n", (*pHead)->m_nValue);
        /// printf("pNew->value = %d\n", pNew->m_nValue);
    } else {
        ListNode* pNode = *pHead;
        while (pNode->m_pNext != NULL) {
            pNode = pNode->m_pNext;
        }
        pNode->m_pNext = pNew;
    }
}

void print(ListNode** pHead) {
    ListNode* pNode = *pHead;
    printf("sz(*pHead) = %d\n", sizeof(*pHead));
    printf("sz(pHead) = %d\n", sizeof(pHead));

    while (pNode != NULL) {
        printf("%d ", pNode->m_nValue);
        pNode = pNode->m_pNext;
    }
    printf("\n");
}

int main()
{
    ListNode** a = NULL;
    ListNode * b = NULL;

    printf("&b = %d\n", &b);
    a = &b;
    if (a != NULL) {
        printf("*a = %d\n", a);
    }
    printf("beg a = %d\n", a);
    printf("sz(a) = %d", sizeof(0.0));
    /// int *b = NULL;
    /// printf("sz(b) = %d\n", sizeof(b));
    puts("\n------------------------------------\n");
    for (int i = 0; i < 10; i++) {
        AddToTail(a, i+1);


        printf("a = %d\n", a);
        printf("*a = %d\n", *a);
    }
    /// print(a);
    return 0;
}
