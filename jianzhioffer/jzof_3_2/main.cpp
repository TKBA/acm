#include <iostream>
#include <cstdio>
#include <cstring>
#include <assert.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;
const int maxn = 10;
const int maxs = 10;
int n = 1, m = 1;
int a[] = {
    9
};

int print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i*n + j]);
        }
        printf("\n");
    }
    return 0;
}

bool Find(int *matrix, int rows, int cols, int number) {
    bool found = false;
    if (matrix != NULL && rows > 0 && cols > 0) {
        int c = cols - 1, r = 0;
        while (r < n && c >= 0) {
            if (matrix[r*cols + c] == number) {
                found = true;
                break;
            }
            if (matrix[r*cols + c] < number) ++r;
            else --c;
        }
    }
    return found;
}

int work() {
    bool has = Find(a, 1, 1, 7);
    if (has == true) puts("Yes");
    else puts("No");
    return 0;
}

int main()
{
    print();
    work();
    return 0;
}
