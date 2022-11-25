#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) { cin >> s[i]; }

  set<char> first = {'H', 'D', 'C', 'S'};
  set<char> second = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

  for (int i = 0; i < n; i++) {
    string si = s[i];
    if (first.count(si[0]) == 0 || second.count(si[1]) == 0) {
      cout << "No" << endl;
      return 0;
    }
    for (int j = 0; j < i; j++) {
      if (s[j] == si) {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;
}