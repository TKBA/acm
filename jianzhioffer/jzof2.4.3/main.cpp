#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int ColInExcl(char* str) {
    if (str == NULL || *str == '\0') {
        puts("Invalid input!");
        exit(1);
    }
    int ret = 0;
    char* p = str;
    while (*p != '\0') {
        if (isupper(*p)) {
            ret = ret * 26 + (int)(*p - 'A' + 1);
        } else {
            puts("Invalid input!");
            exit(1);
        }
        p++;
    }
    return ret;
}

int main()
{
    char s[10];
    while (gets(s)) {
        printf("%d\n", ColInExcl(s));
    }
    return 0;
}
