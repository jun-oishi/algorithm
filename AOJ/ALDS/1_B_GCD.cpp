#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  if (a < b) swap(a, b);
  while (a % b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }

  cout << b << endl;
}
