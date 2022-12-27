#include <bits/stdc++.h>
using namespace std;

int cnt;

void show (vector<int> &v) {
  int n = v.size();
  cout << v[0];
  for (int i = 1; i < n; i++) {
    cout << " " << v[i];
  }
  cout << endl;
}

void insertionSort(vector<int> &a, int g) {
  int n = a.size();
  for (int i = g; i < n; i++) { // O(n^2/g)
    int v = a[i];
    int j = i - g;
    while (j >= 0 && a[j] > v) { // O(n/g)
      a[j + g] = a[j];
      j -= g;
      cnt++;
    }
    a[j + g] = v;
  }
  return;
}

void shellSort(vector<int> &a, int m=4) {
  int n = a.size();
  vector<int> g;
  for (int i = 0; i < m; i++) g.push_back(3*i + 1);
  reverse(g.begin(), g.end());
  cnt = 0;
  for (int i = 0; i < m; i++) insertionSort(a, g[i]);
  cout << "m : " << m << endl;
  cout << "g : ";
  show(g);
  cout << "cnt : " << cnt << endl;
  show(a);
  return;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  show(a);
  shellSort(a);
  return 0;
}
