#include <stdio.h>

int sod(int x) {
    return x%10 + (x%100)/10 + (x%1000)/100 + (x%10000)/1000 +x/10000;
}

int main(void) {
    int n, a, b, ans;
    scanf("%d %d %d", &n, &a, &b);
    ans = 0;

    for (int i=1; i<=n; i++) {
        int s = sod(i);
        if (a <= s && s <= b) {
            ans += i;
        }
    }

    printf("%d", ans);
    return 0;
 }