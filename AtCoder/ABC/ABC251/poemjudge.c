#include <stdio.h>
#include <string.h>

int main(void)
{
    int n, max_t=-1, ans=0;
    scanf("%d", &n);
    char existing_s[n][10];
    for (int i=0; i<n; i++) {
        int t, is_original=1;
        char s[10];
        scanf("%s %d", &s, &t);
        strcpy(existing_s[i], s);
        for (int j=0; j<i; j++) {
            if (strcmp(existing_s[j], s) == 0) {
                is_original = 0;
            }
        }
        if (is_original && t > max_t) {
            ans = i+1;
            max_t = t;
        }
    }
    printf("%d", ans);
}