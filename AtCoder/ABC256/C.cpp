#include <bits/stdc++.h>
using namespace std;

void show(vector<vector<int>> &board) {
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      cout << board[i][j] << ' ';
    }
    cout << "=> " << accumulate(board[i].begin(), board[i].end(), 0);
    cout << endl;
  }
  cout << "---------------" << endl;
  for (int j=0; j<3; j++) {
    cout << board[0][j]+board[1][j]+board[2][j] << ' ';
  }
  cout << endl;
}

int main() {
  int h1, h2, h3, w1, w2, w3;
  cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;
  
  int ans = 0;
  vector<vector<int>> board(3, vector<int>(3,1));
  while (board[0][0] <= h1-2) {
    board[0][1] = 1;
    while (board[0][1] <= h1-board[0][0]-1) {
      board[0][2] = h1 - board[0][0] - board[0][1];
      board[1][0] = 1;
      while (board[1][0] <= h2-2) {
        board[1][1] = 1;
        while (board[1][1] <= h2-board[1][0]-1) {
          board[1][2] = h2 - board[1][0] - board[1][1];

          board[2][0] = w1 - board[0][0] - board[1][0];
          board[2][1] = w2 - board[0][1] - board[1][1];
          board[2][2] = w3 - board[0][2] - board[1][2];
          if (board[2][0] > 0 && board[2][1] > 0 && board[2][2] > 0) {
            // show(board);
            if (h3 == accumulate(board[2].begin(), board[2].end(), 0)) {
              // cout << 'o' << endl;
              ans++;
            } else {
              // cout << 'x' << endl;
            }
          } else {
            // show(board);
            // cout << 'X' << endl;
          }

          board[1][1]++;
        }
        board[1][0]++;
      }
      board[0][1]++;
    }
    board[0][0]++;
  }
  
  cout << ans;
}