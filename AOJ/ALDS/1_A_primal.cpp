#include <bits/stdc++.h>
using namespace std;

void show(int a[], int n) {
  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << a[i];
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];

  show(a, n);
  for (int i = 1; i < n; i++) {
    // a[i-1]まではソート済み
    int v = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > v) {
      if (a[j] < v) break;
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = v;
    show(a, n);
  }
}