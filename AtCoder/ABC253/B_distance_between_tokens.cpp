#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (int i=0; i<h; i++) {
    cin >> s.at(i);
  }

  vector<int> i_tokens, j_tokens;
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      if (s.at(i).at(j) == 'o') {
        i_tokens.push_back(i);
        j_tokens.push_back(j);
      }
    }
  }
  int result = abs(i_tokens.at(0)-i_tokens.at(1)) + abs(j_tokens.at(0)-j_tokens.at(1));
  cout << result << endl;
}