#include<iostream>
#include<vector>
using namespace std;


int main() {
  int h, w;
  vector<vector<int>> a, b;
  vector<int> row_sum, col_sum;
  cin >> h >> w;
  a.resize(h, vector<int>(w, 0));
  b.resize(h, vector<int>(w, 0));
  row_sum.resize(h, 0);
  col_sum.resize(w, 0);

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
      row_sum[i] += a[i][j];
      col_sum[j] += a[i][j];
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      b[i][j] = row_sum[i] + col_sum[j] - a[i][j];
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (j != 0) cout << " ";
      cout << b[i][j];
    }
    cout << endl;
  }

  return 0;
}