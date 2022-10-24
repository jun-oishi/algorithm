#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> a(k), l(q);
  for (int i=0; i<k; i++) {
    cin >> a[i];
  }
  for (int i=0; i<q; i++) {
    cin >> l[i];
  }

  for (int j=0; j<q; j++) {
    int i = l[j]-1;
    if (a[i] >= n) continue;
    if (i>=k) continue;
    if (a[i]+1 == a[i+1]) continue;
    a[i]++;
  }
  cout << endl;

  for (int i=0; i<k; i++) {
    cout << a[i] << ' ';
  }
  cout << endl;
}