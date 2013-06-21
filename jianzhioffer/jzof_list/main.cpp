#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef struct node {
    int val;
    node* next;
}node;

int add_to_tail(node** head, int val) { /// &head != &a but *head == *a
    node* p_new = new node();
    p_new->val = val;
    p_new->next = NULL;

    if (*head == NULL) {
        *head = p_new;
    } else {
        node* p_tmp;
        p_tmp = *head;
        while (p_tmp->next != NULL) {
            p_tmp = p_tmp->next;
        }
        p_tmp->next = p_new;
    }
    return 0;
}

int print(node** head) {
    if (head==NULL || *head == NULL) {
        return 0;
    }
    node* p_tmp = *head;
    while (p_tmp != NULL) {
        printf("%d ", p_tmp->val);
        p_tmp = p_tmp->next;
    }
    return 0;
}

int main()
{
    node* p = NULL;
    node** a = &p; ///  在此处给 a 赋值了，这样后面 head 中的值与 a中的值相同
    /// 即为 p 的地址
    /// 而 p 是一个 node* 型的指针, 他可以存储了node 对象的
    /// 地址， 并且他确实存储的就是链表中第一个元素的地址
    /// p = *a = *head; *p = &(list 中第一个 node());

    for (int i = 1; i <= 1; i++) {
        add_to_tail(a, i);
    }
    print(a);
    return 0;
}
