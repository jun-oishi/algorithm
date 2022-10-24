#include <bits/stdc++.h>
using namespace std;

void show_vector(vector<pair<int, int>> v) {
  int s = v.size();
  for (int i = 0; i < s; i++) {
    cout << "v[" << i << "] = {" << v[i].first << "," << v[i].second << "}" << endl;
  }
}

void show_set(set<int> s) {
  for (int i: s) {
    cout << i << ", ";
  }
  cout << endl;
}

int main() {
  int n, x, y, z;
  cin >> n >> x >> y >> z;
  vector<pair<int, int>> a(n), b(n), c(n);
  for (int i=0; i<n; i++) {
    int ai;
    cin >> ai;
    a[i] = {-ai, i+1};
  }
  for (int i=0; i<n; i++) {
    int bi;
    cin >> bi;
    b[i] = {-bi, i+1};
    c[i] = {-bi + a[i].first, i+1};
  }

  // 同点なら受験番号が若いほうが優先
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  // show_vector(c);

  set<int> ans;
  int count = 0;
  int i = 0;
  while (count < x) {
    ans.insert(a[i].second);
    count++;
    i++;
  }
  // show_set(ans);
  count = 0;
  i = 0;
  while (count < y) {
    if (ans.find(b[i].second) == ans.end()) {
      ans.insert(b[i].second);
      count++;
      i++;
    } else {
      i++;
    }
  }
  // show_set(ans);
  count = 0;
  i = 0;
  while (count < z) {
    if (ans.find(c[i].second) == ans.end()) {
      ans.insert(c[i].second);
      count++;
      i++;
    } else {
      i++;
    }
  }

  for (auto j : ans) {
    cout << j << endl;
  }
}
