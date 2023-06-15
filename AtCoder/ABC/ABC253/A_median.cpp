#include <bits/stdc++.h>
using namespace std;

int get_median(int a, int b, int c) {
  vector<int> v;
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  sort(v.begin(), v.end());
  return v.at(1);
}

int main() {
  int a, b, c, m;
  cin >> a >> b >> c;
  m = get_median(a, b, c);
  if (m == b) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}