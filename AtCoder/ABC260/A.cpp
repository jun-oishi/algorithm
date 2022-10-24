#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<char> s(3);
  for (int i=0; i<3; i++) {
    cin >> s[i];
  }

  char ans = s[0];
  if (s[0] == s[1] && s[0] != s[2]) {
    ans = s[2];
  } else if (s[0] == s[2] && s[0] != s[1]) {
    ans = s[1];
  } else if (s[0] == s[1] && s[1] == s[2]) {
    ans = ' ';
  }
  if (ans == ' ') {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}
