#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int p[a], q[b];
  for (int i = 0; i < a; i++) cin >> p[i];
  for (int i = 0; i < b; i++) cin >> q[i];

  char ans[10];
  for (int i = 0; i < 10; i++) ans[i] = 'x';
  for (int i = 0; i < a; i++) ans[p[i]] = '.';
  for (int i = 0; i < b; i++) ans[q[i]] = 'o';

  printf("%c %c %c %c\n", ans[7], ans[8], ans[9], ans[0]);
  printf(" %c %c %c\n", ans[4], ans[5], ans[6]);
  printf("  %c %c\n", ans[2], ans[3]);
  printf("   %c\n", ans[1]);

  return 0;
}