#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e9;

int main() {
  long long n;
  cin >> n;

  int log3n = log(n) / log(3) + 2;  // < 38
  int log5n = log(n) / log(5) + 2;  // < 18

  long long p3 = 3;
  for (int i = 1; i < log3n; i++) {
    long long p5 = 5;
    for (int j = 1; j < log5n; j++) {
      if (n == p3 + p5) {
        cout << i << " " << j << endl;
        return 0;
      }
      p5 *= 5;
    }
    p3 *= 3;
  }

  cout << -1 << endl;
  return 0;
}