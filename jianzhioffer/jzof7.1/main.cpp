#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stdlib.h>

using namespace std;

template<class Type>
class stack {
private:
    queue<Type> q1;
    queue<Type> q2;
public:
    stack();
    bool empty();
    void push(const Type& item);
    void pop();
    Type top();
};

template<class Type>
stack<Type>::stack() {
    while (!q1.empty()) q1.pop();
    while (!q2.empty()) q2.pop();
}

template<class Type>
bool stack<Type>::empty() {
    return q1.empty() && q2.empty();
}

template<class Type>
void stack<Type>::push(const Type& item) {
    if (q1.empty()) {
        q2.push(item);
    } else {
        q1.push(item);
    }
}

template<class Type>
void stack<Type>::pop() {
    if (q1.empty() && q2.empty()) {
        puts("stack is empty!");
        exit(1);
    }
    if (q1.empty()) {
        while (!q2.empty()) {
            Type top = q2.front();
            q2.pop();
            if (!q2.empty()) {
                q1.push(top);
            }
        }
    } else {
        while (!q1.empty()) {
            Type top = q1.front();
            q1.pop();
            if (!q1.empty()) {
                q2.push(top);
            }
        }
    }
}

template<class Type>
Type stack<Type>:: top() {
    if (q1.empty() && q2.empty()) {
        puts("\nqueue is empty!");
        exit(1);
    }
    Type ret;
    if (q1.empty()) {
        while (!q2.empty()) {
            ret = q2.front();
            q1.push(q2.front());
            q2.pop();
        }
    } else {
        while (!q1.empty()) {
            ret = q1.front();
            q2.push(q1.front());
            q1.pop();
        }
    }
    return ret;
}

int main()
{
    stack<int> s;
    for (int i = 1; i <= 9; i++) {
        s.push(i);
    }
    while (!s.empty()) {
        printf("%d, ",s.top());
        s.pop();
    }
    /// s.pop();
    printf("\n");
    return 0;
}
