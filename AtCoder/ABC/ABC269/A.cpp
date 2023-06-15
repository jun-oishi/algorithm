#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<string> s(10);
  for (int i = 0; i < 10; i++) {
    cin >> s[i];
  }

  int a=0, b=10, c=0, d=10;
  for (int i = 0; i < 10; i++) {
    bool included = false;
    for (int j = 0; j<10; j++) {
      if (s[i][j] == '#') {
        included = true;
        if (a == 0) {
          a = i+1;
        }
        if (c == 0) {
          c = j+1;
        }
      } else {
        if (included && d == 10) {
          d = j;
        }
      }
    }
    if (a != 0 && b==10 && !included) {
      b = i;
    }
  }
  cout << a << " " << b << endl;
  cout << c << " " << d << endl;
}