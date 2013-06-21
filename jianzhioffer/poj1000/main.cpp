#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int a = 0, b = 0;
    while (EOF != scanf("%d%d", &a, &b)) {
        printf("%d\n", a - b);
    }
    return 0;
}
