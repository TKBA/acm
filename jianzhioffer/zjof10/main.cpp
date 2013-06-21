#include <iostream>
#include <cstdio>
#include <limits.h>

using namespace std;

///  边界值分析 负最小
int BitOfInt(int num) {
    int ret = 0, opCnt = 0;
    unsigned int i = 1;
    while (opCnt <= 31) {
        if (num & i) ++ret;
        i = i << 1;
        ++opCnt;
    }
    return ret;
}

int main()
{
    int n = 0;
    n = INT_MIN;
    printf("%d\n", BitOfInt(n));

    while (EOF != scanf("%d", &n)) {
        printf("%d\n", BitOfInt(n));
    }
    return 0;
}
