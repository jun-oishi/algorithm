#include <bits/stdc++.h>
using namespace std;

bool is_misjudgeable(int h, int m) {
  int h1 = h / 10;
  int h2 = h % 10;
  int m1 = m / 10;
  int m2 = m % 10;
  if (h1 == 2 && m1 > 3  // ACが23より大きくなる場合
      || h2 > 5) { // BDが59より大きくなる場合
    return false;
  } else {
    return true;
  }
}

int main() {
  int h, m;
  cin >> h >> m;

  while (true) {
    if (is_misjudgeable(h, m)) {
      cout << h << " " << m << endl;
      return 0;
    }
    m++;
    if (m == 60) {
      m = 0;
      h++;
      if (h == 24) {
        h = 0;
      }
    }
  }
}