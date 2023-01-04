#include <cstdio>
#include <algorithm>
#include <utility>

using card = std::pair<int, char>;

void show(card *A, int n) {
  for (int i = 0; i < n; i++) {
    if (i) printf("\n");
    printf("%c %d", A[i].second, A[i].first);
  }
  printf("\n");
}

// A[p]からA[q-1]までがもとのA[r]が以下、A[q]がもとのA[r]となるように分ける
int partition(card *A, int p, int r) {
  card x = A[r];
  int i = p;
  for (int j = p; j < r; j++) {
    if (A[j].first <= x.first) {
      std::swap(A[i], A[j]);
      i++;
    }
  }
  std::swap(A[i], A[r]);
  return i;
}

// A[p]からA[r]までをソートする
void quickSort(card *A, int p, int r) {
  if (p < r) {
    int q = partition(A, p, r);
    quickSort(A, p, q-1);
    quickSort(A, q+1, r);
  }
}

bool isStable(card *raw, card *sorted, int n) {
  for (int i = 1; i < n; i++) {
    if (sorted[i-1].first == sorted[i].first) {
      for (int j = 0; j < n; j++) {
        if (raw[j] == sorted[i-1]) break;
        if (raw[j] == sorted[i]) return false;
      }
    }
  }
  return true;
}

int main() {
  int n;
  scanf("%d\n", &n);
  card raw[n], sorted[n];
  for (int i = 0; i < n; i++) {
    scanf("%c %d\n", &raw[i].second, &raw[i].first);
    sorted[i] = raw[i];
  }

  quickSort(sorted, 0, n-1);

  if (isStable(raw, sorted, n)) {
    printf("Stable\n");
  } else {
    printf("Not stable\n");
  }
  show(sorted, n);
}