#include <iostream>
#include <string>
#include <vector>

using namespace std;
using Maprow = vector<char>;
using Map = vector<Maprow>;

Maprow shift_row(Maprow r, int t) {
  Maprow res(r.size());
  for (int i=0; i<r.size(); i++) {
    res[(i+t)%r.size()] = r[i];
  }
  return res;
}

Map shift(Map m, int s, int t) {
  Map res(m.size(), Maprow(m[0].size()));
  for (int i=0; i<m.size(); i++) {
    res[(i+s)%m.size()] = shift_row(m[i], t);
  }
  return res;
}

bool match(Map a, Map b) {
  for (int i=0; i<a.size(); i++) {
    for (int j=0; j<a[0].size(); j++) {
      if (a[i][j] != b[i][j]) return false;
    }
  }
  return true;
}

int main() {
  int h, w;
  cin >> h >> w;
  Map a(h, Maprow(w)), b(h, Maprow(w));

  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> b[i][j];
    }
  }

  for (int s=0; s<h; s++) {
    for (int t=0; t<w; t++) {
      if (match(a, shift(b, s, t))) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}