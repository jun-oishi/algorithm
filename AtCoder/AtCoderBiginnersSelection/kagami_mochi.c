#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i=0; i<n; i++) scanf("%d", &a[i]);

    int b[n], max_j=0;
    for (int j=0; j<n; j++) b[j] = 0;
    for (int i=0; i<n; i++) {
        int is_new = 1;
        for (int j=0; j<max_j; j++) {
            if (b[j] > 0 && b[j] == a[i]) {
                is_new = 0;
            }
        }
        if (is_new) {
            b[max_j] = a[i];
            max_j++;
        }
    }

    printf("%d", max_j);
    return 0;
 }