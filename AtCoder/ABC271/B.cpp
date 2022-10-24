#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<vector<int>> vec_seq(n+1);
  for (int i = 1; i <= n; i++) {
    int l;
    cin >> l;
    vector<int> seq(l+1);
    for (int j = 1; j <= l; j++) {
      cin >> seq[j];
    }
    vec_seq[i] = seq;
  }
  for (int i = 0; i < q; i++) {
    int s, t;
    cin >> s >> t;
    cout << vec_seq[s][t] << endl;
  }
}