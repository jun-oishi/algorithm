#include <bits/stdc++.h>
using namespace std;

void show(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i];
  }
  cout << endl;
}

int main() {
  vector<char> s(10);
  for (int i = 0; i < 10; i++) {
    cin >> s[i];
  }
  if (s[0] == '1') {
    cout << "No" << endl;
    return 0;
  }

  vector<int> cols(7);
  cols[0] = s[6] - '0';
  cols[1] = s[3] - '0';
  cols[2] = s[1] - '0' + s[7] - '0';
  cols[3] = s[4] - '0' + s[0] - '0';
  cols[4] = s[2] - '0' + s[8] - '0';
  cols[5] = s[5] - '0';
  cols[6] = s[9] - '0';
  // show(cols);

  string ans = "No";
  for (int i=0; i<=4; i++) {
    if (cols[i] == 0) {
      continue;
    }

    int no_pin_col = 0;
    for (int j=i+1; j<=5; j++) {
      if (cols[j] == 0) {
        no_pin_col = j;
        break;
      }
    }
    if (no_pin_col == 0) {
      continue;
    }

    for (int j = no_pin_col+1; j <= 6; j++) {
      if (cols[j] > 0) {
        ans = "Yes";
        break;
      }
    }
    if (ans == "Yes") {
      break;
    }
  }
  cout << ans << endl;
}