#include <bits/stdc++.h>
using namespace std;

int getGCD(int n1, int n2) {
  if (n1 < n2) {
    int tmp = n1;
    n1 = n2;
    n2 = tmp;
  }
  while (true) {
    int r;
    r = n1 % n2;
    if (r == 0) return n2;
    if (r > n2) {
      n1 = r;
    } else {
      n1 = n2;
      n2 = r;
    }
  }
}

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a.at(i);
  for (int i = 0; i < n; i++) cin >> b.at(i);
  // vector<vector<int>> board(n, vector<int>(n));
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++) {
  //     board.at(i).at(j) = a.at(i) + b.at(j);
  //   }
  // }

  for (int qn = 0; qn < q; qn++) {
    int h1, h2, w1, w2;
    cin >> h1 >> h2 >> w1 >> w2;
    h1--, h2--, w1--, w2--;
    // int gcd = 0;
    // for (int i = h1; i <= h2; i++) {
    //   for (int j = w1; j <= w2; j++) {
    //     if (gcd == 0) {
    //       gcd = board.at(i).at(j);
    //     } else {
    //       gcd = getGCD(board.at(i).at(j), gcd);
    //     }
    //     if (gcd == 1) break;
    //   }
    //   if (gcd == 1) break;
    // }
    // cout << gcd << endl;
    int gcd = a.at(h1) + b.at(w1);
    for (int i=h1+1; i<=h2; i++) {
      gcd = getGCD(abs(a.at(i-1) - a.at(i)), gcd);
    }
    for (int j=w1+1; j<=w2; j++) {
      gcd = getGCD(abs(b.at(j-1) - b.at(j)), gcd);
    }
    cout << gcd << endl;
  }
}