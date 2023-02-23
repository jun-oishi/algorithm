#include <stdio.h>

int main(void) {
    int n, y;
    scanf("%d %d", &n, &y);
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=n-i; j++) {
            int k = n - i - j;
            if (10000*i + 5000*j + 1000*k == y) {
                printf("%d %d %d", i, j, k);
                return 0;
            }
        }
    }
    printf("-1 -1 -1");
    return 0;
 }