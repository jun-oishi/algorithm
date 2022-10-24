#include <bits/stdc++.h>
using namespace std;

void show (int a[], int n) {
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

  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j > i; j--) {
      if (a[j] < a[j - 1]) {
        swap(a[j], a[j - 1]);
        count++;
      }
    }
  }

  show(a, n);
  cout << count << endl;
}