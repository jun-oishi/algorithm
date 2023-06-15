#include <bits/stdc++.h>
using namespace std;

// sup未満で最大最後の要素のindexを返す
// sorted[0]>=supなら-1を返す
int binary_search(int sup, vector<int> &sorted) {
  int left = -1, right = sorted.size();
  while (left < right - 1) {
    int mid = (left + right) / 2;
    if (sorted[mid] >= sup) {
      right = mid;  // つねにsorted[right] >= sup || right==sorted.size()
    } else {
      left = mid;  // つねにsorted[left] < sup
    }
  }
  // ここで left=right-1
  return left;
}

int f(int x, vector<int> &w_a, vector<int> &w_c) {
  int from_c = binary_search(x, w_c) + 1;
  int from_a = (w_a.size() - binary_search(x, w_a) - 1);
  cout << "f(" << x << ") = " << from_c << " children" << " + " << from_a << " adults" << endl;
  return from_c + from_a;
}

int main() {
  int n;
  cin >> n;
  vector<char> s(n);
  vector<int> w_a, w_c;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++) {
    int w;
    cin >> w;
    if (s[i] == '0') {
      w_c.push_back(w);
    } else if (s[i] == '1') {
      w_a.push_back(w);
    }
  };

  sort(w_a.begin(), w_a.end());
  sort(w_c.begin(), w_c.end());
  int ans = 0, x;
  for (int w: w_a) {
    int x_ = w;
    int fx = f(w, w_a, w_c);
    int fx_ = f(w+1, w_a, w_c);
    if (fx < fx_) {
      fx = fx_;
      x_ = w+1;
    }
    if (fx > ans) {
      ans = fx;
      x = x_;
    }
  }
  for (int w: w_c) {
    int x_ = w;
    int fx = f(w, w_a, w_c);
    int fx_ = f(w + 1, w_a, w_c);
    if (fx < fx_) {
      fx = fx_;
      x_ = w + 1;
    }
    if (fx > ans) {
      ans = fx;
      x = x_;
    }
  }
  // cout << x << " -> ";
  cout << ans << endl;
}