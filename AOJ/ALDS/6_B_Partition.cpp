#include <cstdio>
#include <algorithm>

int partition(int *A, int p, int r) {
  int x = A[r];
  int i = p - 1;
  for (int j = p; j < r; j++) {
    if (A[j] <= x) {
      i++;
      std::swap(A[i], A[j]);
    }
  }
  std::swap(A[i + 1], A[r]);
  return i + 1;
}

int main() {
  int n;
  scanf("%d", &n);
  int A[n];
  for (int i = 0; i < n; i++) scanf("%d", &A[i]);

  int q = partition(A, 0, n - 1);

  for (int i = 0; i < n; i++) {
    if (i) printf(" ");
    if (i == q) printf("[");
    printf("%d", A[i]);
    if (i == q) printf("]");
  }
  printf("\n");
}