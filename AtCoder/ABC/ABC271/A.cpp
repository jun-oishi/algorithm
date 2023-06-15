#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int a = n / 16;
  int b = n % 16;
  char a_, b_;
  if (a < 10) {
    a_ = '0' + a;
  } else {
    a_ = 'A' + (a - 10);
  }
  if (b < 10) {
    b_ = '0' + b;
  } else {
    b_ = 'A' + (b - 10);
  }
  cout << a_ << b_ << endl;
}