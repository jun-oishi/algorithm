#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  int s_length = s.length();
  int t_length = t.length();
  bool ans = s[0] == t[0] && s[1] == t[1];
  int i=2, j=2;
  while (ans && i < s_length && j < t_length) {

    if (s[i] == t[j]) {
      i++;
      j++;
    } else if (t[i] == s[i-1] && s[i-1] == s[i-2]) {
      // s = XXXaabXXX, t = XXXaaaXXX の形なら続行
      j++;
    } else {
      ans = false;
    }
  }

  if (i < s_length) {
    // s = XXXaab, t = XXXaaa の形の場合
    ans = false;
  }
  if (j < t_length) {
    // s = XXXaa, t = XXXaaa の形ならok
    for (j; j<t_length; j++) {
      if (t[j] != s[i-1]) {
        ans = false;
        break;
      }
    }
  }

  if (ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}