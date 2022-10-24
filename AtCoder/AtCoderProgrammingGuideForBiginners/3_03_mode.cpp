#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, ai;
  map<int, int> a;
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> ai;
    if (a.count(ai)) {
      a.at(ai)++;
    } else {
      a[ai] = 1;
    }
  }

  int max=0;
  int mode;
  for (auto it=a.begin(); it!=a.end(); it++) {
    if (it->second > max) {
      max = it->second;
      mode = it->first;
    }
  }
  cout << mode << ' ' << max << endl;
}