#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int t[n+1], x[n+1], y[n+1];
    t[0] = 0;
    x[0] = 0;
    y[0] = 0;
    for (int i=1; i<=n; i++) scanf("%d %d %d", &t[i], &x[i], &y[i]);

    int dt, dx, dy;
    for (int i=0; i<n; i++) {
        dt = t[i+1] - t[i];
        dx = abs(x[i+1] - x[i]);
        dy = abs(y[i+1] - y[i]);
        if (dx + dy > dt || (dx + dy - dt) % 2 == 1) {
            printf("No");
            return 0;
        }
    }

    printf("Yes");
    return 0;
 }