#include <bits/stdc++.h>
using namespace std;

// v[m]より上の位の10進表示をbとして下位を0,1として得られる数を出力する
void rec(vector<int> v, int m, long long b) {
  if (m > 0) {
    rec(v, m-1, b);
    b = (b | (1ll << v[m]));
    rec(v, m-1, b);
    return;
  } else if (m == 0) {
    cout << b << endl;
    b = (b | (1ll << v[m]));
    cout << b << endl;
    return;
  }
}

int main() {
  long long n;
  cin >> n;

  // n = sum(2^v[i]) となるようなvを求める
  vector<int> v;
  for (int i=0; i<60; i++) {
    if (n&(1ll<<i)) {
      v.push_back(i);
    }
  }

  int m = v.size()-1;
  if (m==-1) {
    cout << 0 << endl;
    return 0;
  }
  rec(v, m, 0);
}