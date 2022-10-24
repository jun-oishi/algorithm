#include <bits/stdc++.h>
using namespace std;

using ci = pair<char, int>;
using v_ci = vector<ci>;

v_ci rle(string s) {
  int cnt = 1;
  int len = s.size();
  v_ci ret;
  for (int i=1; i<len; i++) {
    if (s[i] == s[i-1]) {
      cnt++;
    } else {
      ret.push_back({s[i-1], cnt});
      cnt = 1;
    }
  }
  ret.push_back({s[len-1], cnt});
  return ret;
}

int main() {
  string s, t;
  cin >> s >> t;

  v_ci s_rle = rle(s);
  v_ci t_rle = rle(t);

  // if (s_rle.size() != t_rle.size()) {
  //   cout << "No" << endl;
  //   return 0;
  // }
  // int len = s_rle.size();
  // for (int i=0; i<len; i++) {
  //   if (s_rle[i].first != t_rle[i].first) {
  //     cout << "No" << endl;
  //     return 0;
  //   }
  //   if (
  //     s_rle[i].second != t_rle[i].second 
  //     && s_rle[i].second < 2
  //   ) {
  //     cout << "No" << endl;
  //     return 0;
  //   }
  // }
  // cout << "Yes" << endl;
}