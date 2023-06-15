#include <bits/stdc++.h>
using namespace std;

void show(deque<char> s) {
  int n = s.size();
  for (int i=0; i<n; i++) {
    cout << s.front();
    s.pop_front();
  }
  cout << endl;
}

int main() {
  int n, q;
  cin >> n >> q;
  deque<char> s;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    s.push_back(c);
  }

  // v[i] : i回処理した文字列の先頭
  // == p回処理した文字列のj文字目(i=p-j)
  vector<char> v(n);
  for (int i = 0; i < n; i++) {
    v[i] = s.front();
    // show(s);
    char c = s.back();
    s.pop_back();
    s.push_front(c);
  }

  int p = 0;
  for (int i=0; i<q; i++) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      p += x;
      if (p >= n) p -= n;
    } else if (t == 2) {
      int p_ = p;
      p_ -= x-1;
      if (p_ < 0) p_ += n;
      cout << v[p_] << endl;
    }
  }
}