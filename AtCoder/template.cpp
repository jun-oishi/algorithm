#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  vector<int> v;
  a = 10;
  cin >> b;
  v.emplace_back(a);
  v.emplace_back(b);
  cout << "a = " << a << ", b = " << b << endl;
  if (a > b) {
    cout << "a > b" << endl;
  } else if (a == b) {
    cout << "a == b" << endl;
  } else {
    cout << "a < b" << endl;
  }
  for (int i = 0; i<v.size(); i++) {
    cout << "v[i] = " << v[i] << endl;
  }
  return 0;
}
