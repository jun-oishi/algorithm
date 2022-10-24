#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  map<string, int> m;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (m.count(s) == 0) {
      cout << s << endl;
      m[s] = 1;
    } else {
      cout << s << '(' << m[s] << ')' << endl;
      m[s]++;
    }
  }
}
