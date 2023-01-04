#include <iostream>

const int INF = 1+1e9;

using ll = long long;

// A[left]からA[mid-1]とA[mid]からA[right-1](それぞれソート済)をマージする
ll merge(int *A, int left, int mid, int right) {
  ll c = 0;
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1+1], R[n2+1];
  for (int i = 0; i < n1; i++) L[i] = A[left+i];
  for (int i = 0; i < n2; i++) R[i] = A[mid+i];
  L[n1] = R[n2] = INF;
  int i = 0, j = 0;
  for (int k = left; k < right; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
      c += n1 - i;
    }
  }
  return c;
}

// A[left]からA[right-1]までをソートする
ll mergeSort(int *A, int left, int right) {
  if (left < right - 1) {
    ll c;
    int mid = (left + right) / 2;
    c = mergeSort(A, left, mid);
    c += mergeSort(A, mid, right);
    c += merge(A, left, mid, right);
    return c;
  } else {
    return 0;
  }
}

int main() {
  int n;
  std::cin >> n;
  int A[n];
  for (int i = 0; i < n; i++) std::cin >> A[i];

  ll ans = mergeSort(A, 0, n);
  std::cout << ans << std::endl;
}