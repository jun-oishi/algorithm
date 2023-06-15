#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

void showVi(vector<int> vi) {
  int n = vi.size();
  cout << vi[0];
  for (int i = 1; i < n; i++) {
    cout << " " << vi[i];
  }
  cout << endl;
}

// a のはじめからi-1個の要素をreplacementに置き換えると和が最小になるか求めて返す
// 1個も置き換えられない場合は-1を返す
// O(n)
int searchMinIdx(vi& a, int replacement) {
  int n = a.size();
  vi diff(n);
  for (int i = 0; i < n; i++) {
    diff[i] = replacement - a[i];
  }
  vi sum_diff(n);
  sum_diff[0] = diff[0];
  for (int i = 1; i < n; i++) {
    sum_diff[i] = sum_diff[i - 1] + diff[i];
  }
  // cout << "sum_diff=";
  // showVi(sum_diff);
  int min_sum = sum_diff[0];
  int min_idx = 0;
  for (int i = 1; i < n; i++) {
    if (sum_diff[i] < min_sum) {  // <- <=であるべき？
      min_sum = sum_diff[i];
      min_idx = i;
    }
  }
  if (min_sum < 0) {
    return min_idx;
  } else {
    return -1;
  }
}

int main() {
  int n, l, r;
  cin >> n >> l >> r;
  vi a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int x = searchMinIdx(a, l) + 1;
  for (int i=0; i<x; i++) {
    a[i] = l;
  }
  // cout << "x=" << x << endl;
  // showVi(a);

  vi a_rev(n);
  for (int i = 0; i < n; i++) {
    a_rev[i] = a[n - i - 1];
  }
  // cout << "a_rev=";
  // showVi(a_rev);
  int y = searchMinIdx(a_rev, r) + 1;
  for (int i=0; i<y; i++) {
    a[n-1-i] = r;
  }
  int ans=0;
  for (int i=0; i<n; i++) {
    ans += a[i];
  }
  // cout << "y=" << y << endl;
  // showVi(a);
  cout << ans << endl;
}
