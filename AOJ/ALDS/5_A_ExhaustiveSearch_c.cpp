#include <cstdio>

const int MAX_N = 20;
const int MAX_M = 2000;

int n, q;
int A[MAX_N];
int solved[MAX_N][MAX_M];

// i番目以降の要素でmを作れればtrueを返す
bool solve(int i, int m) {
  if (solved[i][m] != -1) return solved[i][m];
  if (m == 0) {
    solved[i][m] = 1;
    return true;
  }
  if (i >= n) {
    solved[i][m] = 0;
    return false;
  }
  solved[i][m] = 0 + (solve(i + 1, m) || solve(i + 1, m - A[i]));
  return solved[i][m];
}

int main() {
  for (int i = 0; i < MAX_N; i++) {
    for (int j = 0; j < MAX_M; j++) {
      solved[i][j] = -1;
    }
  }

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