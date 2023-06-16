#include <bits/stdc++.h>
using namespace std;

set<char> v = {'a', 'i', 'u', 'e', 'o'};

int main() {
  string w, ans;
  cin >> w;
  for (char c : w) {
    if (v.count(c) == 0) {
      ans += c;
    }
  }
  cout << ans << endl;
  return 0;
}