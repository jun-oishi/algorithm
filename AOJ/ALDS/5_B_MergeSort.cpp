#include <cstdio>

const int INF = 1 + 1e9;

int count = 0;

// A[left]~A[mid-1]とA[mid]~A[right-1]がそれぞれ整列している配列をマージする
void merge(int *A, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1 + 1], R[n2 + 1];
  for (int i = 0; i < n1; i++) L[i] = A[left + i];
  for (int i = 0; i < n2; i++) R[i] = A[mid + i];
  L[n1] = R[n2] = INF;
  int i = 0, j = 0;
  for (int k = left; k < right; k++) {
    count++;
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
  }
  return;
}

// A[left]~A[right-1]を整列する
void mergeSort(int *A, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
  return;
}

void show(int *A, int n) {
  for (int i = 0; i < n; i++) {
    if (i) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

int main() {
  int n;
  scanf("%d", &n);
  int A[n];
  for (int i = 0; i < n; i++) scanf("%d", &A[i]);

  mergeSort(A, 0, n);

  show(A, n);
  printf("%d\n", count);
}