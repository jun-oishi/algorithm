#include <bits/stdc++.h>
using namespace std;

// n回のときの期待値を求める
double calc(int n) {
  if (n==1) return 3.5;
  double after = calc(n-1);
  double sum = 0;
  for (int i=1; i<=6; i++) {
    if (i < after) {
      sum += after;
    } else {
      sum += i;
    }
  }
  return sum / 6;
}

int main() {
  int n;
  cin >> n;
  float ans = calc(n);
  cout << fixed << setprecision(10);
  cout<< ans << endl;
}
