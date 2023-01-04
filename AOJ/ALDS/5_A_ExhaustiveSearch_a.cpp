#include <cstdio>
#include <bitset>

const int MAX_N = 20;

int n, q;
int A[MAX_N];

int getSum(std::bitset<MAX_N> flg) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (flg[i]) sum += A[i];
  }
  return sum;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &A[i]);
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int m;
    scanf("%d", &m);
    bool ans = false;
    for (int i = 0; i < (1 << n); i++) {
      std::bitset<MAX_N> flg(i);
      if (getSum(flg) == m) {
        ans = true;
        break;
      }
    }
    if (ans) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
  }
}