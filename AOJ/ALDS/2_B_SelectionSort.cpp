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
    int mini = i;
    for (int j = i; j < n; j++) {
      if (a[j] < a[mini]) mini = j;
    }
    swap(a[i], a[mini]);
    if (i != mini) count++;
  }

  show(a, n);
  cout << count << endl;
}