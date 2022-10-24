#include <bits/stdc++.h>
using namespace std;

void del_row(vector<vector<char>> &v, int n) {
  int h = v.size();
  for (int i=n; i<h-1; i++) {
    v.at(i) = v.at(i+1);
  }
  v.pop_back();
}

void del_col(vector<vector<char>> &v, int n) {
  int h = v.size();
  int w = v.at(0).size();
  for (int i=0; i<h; i++) {
    for (int j=n; j<w-1; j++) {
      v.at(i).at(j) = v.at(i).at(j+1);
    }
    v.at(i).pop_back();
  }
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> table(h, vector<char>(w));
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      cin >> table.at(i).at(j);
    }
  }
  
  for (int i=0; i<h; i++) {
    bool is_all_white_row = true;
    for (int j=0; j<w; j++) {
      if (table.at(i).at(j) != '.') {
        is_all_white_row = false;
        break;
      }
    }
    if (is_all_white_row) {
      del_row(table, i);
      h--;
      i--;
    }
  }
  for (int j=0; j<w; j++) {
    bool is_all_white_col = true;
    for (int i=0; i<h; i++) {
      if (table.at(i).at(j) != '.') {
        is_all_white_col = false;
        break;
      }
    }
    if (is_all_white_col) {
      del_col(table, j);
      w--;
      j--;
    }
  }
  
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      cout << table.at(i).at(j);
    }
    cout << endl;
  }
}