#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  using rst = tuple<string, int, int>;
  vector<rst> v;
  string s;
  int p;
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> s >> p;
    v.push_back(make_tuple(s, 100-p, i+1));
  }

  sort(v.begin(), v.end());

  int i;
  for (int j=0; j<n; j++) {
    tie(s, p, i) = v.at(j);
    cout << i << endl;
  }
}