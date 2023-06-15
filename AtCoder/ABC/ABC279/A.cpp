#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int ans = 0;
  for (char c : s) {
    if (c == 'w') {
      ans += 2;
    } else if (c == 'v') {
      ans++;
    }
  }
  cout << ans << endl;
}