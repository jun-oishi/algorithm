#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v;
  for (int i=0; i<4; i++) {
    char c;
    cin >> c;
    v.push_back(int(c-'0'));
  }

  string ans = "";
  for (int i=0; i < (1<<3); i++) {
    bitset<3> operators(i);
    int result = v.at(0);
    for (int j=0; j<3; j++) {
      if (operators.test(j)) {
        result += v.at(j+1);
      } else {
        result -= v.at(j+1);
      }
    }
    if (result == 7) {
      ans += to_string(v.at(0));
      for (int j=0; j<3; j++) {
        if (operators.test(j)) {
          ans += "+";
        } else {
          ans += "-";
        }
        ans += to_string(v.at(j+1));
      }
      ans += "=7";
      break;
    }
  }

  cout << ans << endl;
}
