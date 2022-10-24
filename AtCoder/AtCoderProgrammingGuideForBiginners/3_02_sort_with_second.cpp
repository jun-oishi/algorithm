#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  using pii = pair<int, int>;
  vector<pii> v;
  int a, b;
  for (int i=0; i<n; i++) {
    cin >> a >> b;
    v.push_back(make_pair(b, a));
  }

  sort(v.begin(), v.end());
  for (int i=0; i<n; i++) {
    tie(b, a) = v.at(i);
    cout << a << ' ' << b << endl;
  }
}