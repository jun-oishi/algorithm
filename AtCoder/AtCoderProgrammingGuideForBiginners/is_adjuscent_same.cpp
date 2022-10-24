#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> a(5);
  for (int i=0; i<5; i++) cin >> a.at(i);

  for (int i=0; i<4; i++) {
    if (a.at(i) == a.at(i+1)) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}