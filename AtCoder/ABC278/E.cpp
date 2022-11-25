#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// O(9e4*??)
int count_distinct_numbers(vector<vector<int>> &A, int k, int l, int h, int w) {
  set<int> s;
  int H = A.size() - 1, W = A[0].size() - 1;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      bool ignore = (k < i && i <= k + h && l < j && j <= l + w);
      if (!ignore) {
        // cout << "(" << i << "," << j << ")=" << A[i][j] << " ";
        s.insert(A[i][j]);
      } else {
        // cout << "(" << i << "," << j << ")=" << "X" << " ";
      }
    }
  }
  // cout << "k:" << k << " l:" << l << " -> ";
  for (auto x : s) {
    // cout << x << " ";
  }
  // cout << endl;
  return s.size();
}

int main() {
  int H, W, N, h, w;
  cin >> H >> W >> N >> h >> w;
  vector<vector<int>> A(H+1, vector<int>(W+1, 0));
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      cin >> A.at(i).at(j);
    }
  }

  for (int k = 0; k <= H - h; k++) {
    cout << count_distinct_numbers(A, k, 0, h, w);
    // cout << endl;
    for (int l = 1; l <= W - w; l++) {
      cout << " " << count_distinct_numbers(A, k, l, h, w);
      // cout << endl;
    }
    cout << endl;
  }
}