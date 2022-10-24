#include <stdio.h>
#include <string.h>

int main(void) {
    char s[100000];
    char t[100000]="";
    char u[100000];
    scanf("%s", &s);

    for (int i=0; i<20000; i++) {
        if (strlen(s)==strlen(t)) {
            printf("YES");
            break;
        }

        strcpy(u, t);
        strcat(u, "dreamer");
        if (strncmp(s, u, strlen(u))==0) {
            strcat(t, "dreamer");
            continue;
        }

        strcpy(u, t);
        strcat(u, "eraser");
        if (strncmp(s, u, strlen(u)) == 0)
        {
            strcat(t, "eraser");
            continue;
        }

        strcpy(u, t);
        strcat(u, "dream");
        if (strncmp(s, u, strlen(u)) == 0)
        {
            strcat(t, "dream");
            continue;
        }

        strcpy(u, t);
        strcat(u, "erase");
        if (strncmp(s, u, strlen(u)) == 0)
        {
            strcat(t, "erase");
            continue;
        }

        printf("NO");
        break;
    }

    return 0;
 }