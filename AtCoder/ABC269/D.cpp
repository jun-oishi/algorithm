#include <bits/stdc++.h>
using namespace std;

vector<int> X, Y;

bool in(int i, vector<int> group) {
  int x = X[i], y = Y[i];
  for (int j: group) {
    if ((x == X[j] - 1 && y == Y[j] - 1) ||
        (x == X[j] - 1 && y == Y[j]    ) ||
        (x == X[j]     && y == Y[j] - 1) ||
        (x == X[j]     && y == Y[j] + 1) ||
        (x == X[j] + 1 && y == Y[j]    ) ||
        (x == X[j] + 1 && y == Y[j] + 1)
    ) {
      return true;
    };
  }
  return false;
}

// (x,y)をグループに加える
void add(int i, vector<vector<int>> &groups) {
  // todo: 結合の判定と処理
  int j = 0;
  int in_other = -1;
  while (true) {
    if (j >= groups.size()) {
      break;
    }
    if (in(i, groups[j])) {
      if (in_other == -1) {
        // まだ他のグループに入っていない
        groups[j].push_back(i);
        in_other = j;
        j++;
      } else {
        // groups[in_other]とgroups[j]を結合
        for (int k: groups[j]) {
          groups[in_other].push_back(k);
        }
        groups.erase(groups.begin() + j);
        // jは変化しない
      }
    } else {
      j++;
    }
  }

  if (in_other == -1) {
    // 他のグループに入っていない
    groups.push_back({i});
  }
  return;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    X.push_back(x);
    Y.push_back(y);
  }

  // groups = { {連結なマスのインデックス}, {.,,}, ... }
  vector<vector<int>> groups;
  for (int i=0; i<n; i++) {
    add(i, groups);
  }
  cout << groups.size() << endl;
}