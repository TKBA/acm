#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char* chang_str(char* str) {
    if (str == NULL) return NULL;
    int len = (int)strlen(str), space_cnt = 0;
    for (int i = 0; i < len; i++) if (isspace(str[i])) ++space_cnt;
    int newlen = len + space_cnt*2 + 1;
    if (0 == space_cnt) return str;

    for (int i = len-1; i >= 0; i--) {
        if (!isspace(str[i])) {
            str[i + space_cnt*2] = str[i];
        } else {
            str[i + space_cnt*2] = '0';
            str[i + space_cnt*2 - 1] = '2';
            str[i + space_cnt*2 - 2] = '%';
            --space_cnt;
        }
    }
    str[newlen] = '\0';
    return str;
}

int cha_str(char* str, int able_len) {
    int len = (int)strlen(str), newlen = 0, space_cnt = 0;
    for (int i = 0; i < len; i++) if (isspace(str[i])) ++space_cnt;
    newlen = len + space_cnt*2;
    if (0 == space_cnt) return 0;
    if (str == NULL) return 0;
    if (newlen > able_len) return 0;

    while (len >= 0) {
        if (isspace(str[len])) {
            str[newlen--] = '0';
            str[newlen--] = '2';
            str[newlen--] = '%';
        } else {
            str[newlen--] = str[len];
        }
        --len;
    }
    return 0;
}

int main()
{
    char a[100] = "he llo ";
    cha_str(a, strlen(a)*3);
    puts(a);
    return 0;
}
