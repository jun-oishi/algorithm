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
  vector<int> h, w;
  for (int i = 0; i < 3; i++) cin >> h[i];
  for (int i = 0; i < 3; i++) cin >> w[i];
  
  int ans = 0;
  vector<vector<int>> board(3, vector<int>(3,1));
  for (board[0][0]=1; board[0][0]<=30; board[0][0]++) {
    for (board[0][1] = 1; board[0][1] <= 30; board[0][1]++) {
      if (board[0][0]+board[0][1]>=h[0]) continue;
      board[0][2] = h[0] - board[0][0] - board[0][1];
      for (board[1][0]=0; board[1][0]<=30; board[1][0]++) {
        for (board[1][1]=0; board[1][1]<=30; board[1][1]++) {
          if (board[1][0]+board[1][1]>=h[1]) continue;
          board[1][2] = h[1]-board[1][0]-board[1][1];
          for (int i=0; i<3; i++) {
            if (board[0][i]+board[1][i]>=w[i]) continue;
            board[2][i] = w[i]-board[0][i]-board[1][i];
          }
          if (board[2][0]+board[2][1]+board[2][2]==h[2]) ans++;
        }
      }
    }
  }
  cout << ans;
}