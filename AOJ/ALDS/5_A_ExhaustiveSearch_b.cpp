#include <cstdio>

const int MAX_N = 20;
const int MAX_M = 2000;

int n, q;
int A[MAX_N];

// i番目以降の要素でmを作れればtrueを返す
bool solve(int i, int m) {
  if (m == 0) {
    return true;
  }
  if (i >= n) {
    return false;
  }
  return solve(i + 1, m) || solve(i + 1, m - A[i]);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &A[i]);
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int m;
    scanf("%d", &m);
    if (solve(0, m)) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
  }
}