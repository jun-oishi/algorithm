#include <iostream>
#include <string>
#include <vector>

using namespace std;

int h, w;
vector<vector<char>> c;

// (i,j)がバツ印の中心ならtrueを返す
bool is_center(int i, int j) {
  if (i==0 || i==h-1 || j==0 || j==w-1) {
    return false;
  }
  if (
    c[i-1][j-1] == '#' && c[i-1][j+1] == '#'
    && c[i+1][j-1] == '#' && c[i+1][j+1] == '#'
  ) {
    return true;
  }
  return false;
}

// (i,j)を中心とするバツ印の大きさを返す
int measure(int i, int j) {
  int d=1;
  while (i-d-1>=0 && i+d+1<h && j-d-1>=0 && j+d+1<w) {
    if (c[i+d+1][j+d+1] == '#') {
      d++;
      continue;
    } else {
      break;
    }
  }
  return d;
}

int main() {
  cin >> h >> w;
  c.resize(h);
  for (int i=0; i<h; i++) {
    c[i].resize(w);
    for (int j=0; j<w; j++) {
      cin >> c[i][j];
    }
  }

  int n = h>w ? w : h;
  vector<int> s(n+1, 0);
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      if (is_center(i,j)) {
        int d = measure(i,j);
        s[d]++;
      }
    }
  }

  for (int i=1; i<=n; i++) {
    if (i-1) cout << ' ';
    cout << s[i];
  }
  cout << endl;
}