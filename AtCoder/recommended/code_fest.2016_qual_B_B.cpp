#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  int count = 0;
  int fs_count = 0;
  for (char c : s) {
    if (count >= a + b || c == 'c') {
      cout << "No" << endl;
    } else {
      if (c == 'a') {
        count++;
        cout << "Yes" << endl;
      } else {
        if (fs_count < b) {
          count++;
          fs_count++;
          cout << "Yes" << endl;
        } else {
          cout << "No" << endl;
        }
      }
    }
  }
}