#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int StrToInt(const char* str) {
    if (str == NULL) {
        puts("\nNULL point error, Invalid input");
        exit(1);
    }

    int i = 0, simbol = 1, len = 0;
    long long limit = 0x7FFFFFFF, ret = 0;
    len = (int)strlen(str);
    if (0 == len) {
        ret = 0;
        puts("\nIvalid input!");
        exit(0);
    }

    if ('+' == str[i] || '-' == str[i]) {
        if (1 == len) {
            ret = 0;
            puts("\nInvalid input");
            exit(1);
        }
        simbol = ('-' == str[i]) ? (-1) : 1;
        if (-1 == simbol) ++limit;
        ++i;
    }
    if (len > 12) {
        ret = 0;
        puts("\nNot in the region of int");
        exit(1);
    }
    int j = i, prezero = 0;
    while (j <len && str[j++] == '0') ++prezero;
    if (prezero > 1) {
        puts("Invalid input");
        exit(1);
    }

    while (i < len) {
        if (!isdigit(str[i])) {
            ret = 0;
            puts("\nHas invalid char, change stop!");
            exit(1);
        } else {
            ret = ret * 10 + (int)(str[i] - '0');
        }
        if (ret > limit) {
            ret = 0;
            puts("\nNot in the region of int");
            exit(1);
        }
        ++i;
    }
    return (int)(simbol*ret);
}

int main()
{
    char s[100];
    while (EOF != scanf("%s", s)) {
        printf("%d\n", StrToInt(s));
    }
    return 0;
}
