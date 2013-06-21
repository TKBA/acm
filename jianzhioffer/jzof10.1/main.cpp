#include <iostream>
#include <cstdio>
#include <cstring>
#include <limits.h>

using namespace std;

int BitOfInt(int num) {
    int cnt = 0;
    while (num) {
        num = num & (num -1);
        ++cnt;
    }
    return cnt;
}

int main()
{
    int n = 0;
    n = 0xFFFFFFFF;
    printf("%d\n", BitOfInt(n));
    while (EOF != scanf("%d", &n)) {
        printf("%d\n", BitOfInt(n));
    }
    return 0;
}
