#include <stdio.h>

int main(void) {
    int n, i, j;
    scanf("%d", &n);
    int a[n];
    for (i=0; i<n; i++) scanf("%d", &a[i]);

    int alice, bob, ans, idx;
    alice = 0;
    bob = 0;
    for (i=0; i<n; i++) {
        int idx = 0;
        int max = a[idx];
        for (j=1; j<n; j++) {
            if (a[j] > max) {
                max = a[j];
                idx = j;
            }
        }
        a[idx] = 0;
        if (i % 2 == 0) {
            alice += max;
        } else {
            bob += max;
        }
    }
    ans = alice - bob;

    printf("%d", ans);
    return 0;
 }