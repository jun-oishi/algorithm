#include <bits/stdc++.h>
using namespace std;

void show_vector(vector<vector<bool>> &checked) {
  int h = checked.size();
  int w = checked.at(0).size();
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      if (checked.at(i).at(j)) {
        cout << 'o';
      } else {
        cout << 'x';
      }
    }
    cout << endl;
  }
  return;
}

vector<vector<bool>> fill(vector<vector<bool>> map, int i, int j) {
  map.at(i).at(j) = true;
  return map;
}

void get_united(vector<vector<bool>> &map,
                vector<vector<bool>> &checked,
                int i, int j
) {
  if (i<0 || j<0 || i>=map.size() || j>=map.at(0).size()) return;
  if (!map.at(i).at(j)) return;
  if (checked.at(i).at(j)) return;

  checked.at(i).at(j) = true;
  get_united(map, checked, i - 1, j);
  get_united(map, checked, i + 1, j);
  get_united(map, checked, i, j - 1);
  get_united(map, checked, i, j + 1);
  return;
}

bool is_united(vector<vector<bool>> &map) {
  int h = map.size(), w = map.at(0).size();
  vector<vector<bool>> checked(h, vector<bool>(w, false));

  int i_ini=-1, j_ini=-1;
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      if (map.at(i).at(j)) {
        i_ini = i;
        j_ini = j;
        break;
      }
    }
    if (i_ini != -1) break;
  }

  get_united(map, checked, i_ini, j_ini);
  // show_vector(checked);

  bool ret = true;
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      if (map.at(i).at(j) && !checked.at(i).at(j)) {
        ret = false;
        cout << "not match at " << i << ',' << j << endl;
        break;
      }
    }
    if (ret == false) break;
  }
  return ret;
}

int main() {
  vector<vector<bool>> map(10, vector<bool>(10, false));
  int h = 10, w = 10;
  for (int i=0; i<h; i++) {
    for (int j=0; j<h; j++) {
      char c;
      cin >> c;
      if (c == 'o') map.at(i).at(j) = true;
    }
  }

  bool ans = false;
  for (int i=0; i<h; i++) {
    for (int j=0; j<h; j++) {
      cout << "fill " << i << "," << j << endl;
      vector<vector<bool>> filled_map = fill(map, i, j);
      if (is_united(filled_map)) {
        ans = true;
        break;
      }
    }
    if (ans) break;
  }


  if (ans) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}