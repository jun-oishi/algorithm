#include <bits/stdc++.h>
using namespace std;

// 2xの計算で繰り上がりがあってf(2x)>2f(x)となることはない

int main() {
  int n;
  cin >> n;

  int m = 2 * n;
  cout << m << endl;
  int a = n % 4;
  if (a != 0) {
    cout << a;
  }
  for (int i = 1; i <= (n - a) / 4; i++) {
    cout << 4;
  }
  cout << endl;
}
