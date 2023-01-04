#include <cstdio>

void show(int *A, int n) {
  for (int i = 0; i < n; i++) {
    if (i) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

void countingSort(int *source, int *dist, int max, int n) {
  int C[max+1];
  for (int i = 0; i <= max; i++) {
    C[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    C[source[i]]++;
  }
  for (int i = 1; i <= max; i++) {
    C[i] += C[i-1];
  }
  for (int i = n-1; i >= 0; i--) {
    dist[--C[source[i]]] = source[i];
  }
}

int main() {
  int n;
  scanf("%d\n", &n);
  int source[n], dist[n];
  int max = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &source[i]);
    if (source[i] > max) max = source[i];
  };
  countingSort(source, dist, max, n);
  show(dist, n);
}