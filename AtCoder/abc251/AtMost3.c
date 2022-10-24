#include <stdio.h>

int main(void)
{
    int n, w;
    scanf("%d %d", &n, &w);
    int a[n], b[w];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < w; i++)
        b[i] = 0;

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int good[7] = {
                    a[i], a[j], a[k],
                    a[i] + a[j], a[j] + a[k], a[k] + a[i],
                    a[i] + a[j] + a[k]};
                for (int l = 0; l < 7; l++)
                {
                    if (good[l] <= w)
                    {
                        b[good[l]] = 1;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < w; i++)
    {
        ans += b[i];
    };
    printf("\n%d", ans);
}