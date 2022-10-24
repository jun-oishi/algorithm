#include <bits/stdc++.h>
using namespace std;

void check_from(vector<vector<char>> &board, vector<vector<bool>> &checked, int i_s, int j_s) {
  int h = checked.size();
  int w = checked.at(0).size();
  if (
      (i_s < 0 || i_s >= h || j_s < 0 || j_s >= w)
      || board.at(i_s).at(j_s) == '#'
      || checked.at(i_s).at(j_s) == true
  ) {
    return;
  }

  checked.at(i_s).at(j_s) = true;
  check_from(board, checked, i_s - 1, j_s);
  check_from(board, checked, i_s + 1, j_s);
  check_from(board, checked, i_s, j_s - 1);
  check_from(board, checked, i_s, j_s + 1);
}

bool can_reach(vector<vector<char>> &board, int i_s, int j_s, int i_g, int j_g) {
  vector<vector<bool>> checked(board.size(), vector<bool>(board.at(0).size(), false));
  check_from(board, checked, i_s, j_s);
  if (checked.at(i_g).at(j_g)) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> board(h, vector<char>(w));
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      cin >> board.at(i).at(j);
    }
  }

  int i_s, j_s, i_g, j_g;
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      if (board.at(i).at(j) == 's') {
        i_s = i;
        j_s = j;
      } else if (board.at(i).at(j) == 'g') {
        i_g = i;
        j_g = j;
      }
    }
  }

  bool ans = can_reach(board, i_s, j_s, i_g, j_g);
  if (ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}