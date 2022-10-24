#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

void dfs() {
}

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  vvi g(n+1, vi());
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  // TLE

  vector<bool> visited(n+1, false);
  visited[x] = true;
  deque<int> path = {x};

  while (true) {
    int cur = path.back();
    if (cur == y) break;
    for (int next: g[cur]) {
      if (visited[next]) continue;
      visited[next] = true;
      path.push_back(next);
      break;
    }
    if (path.back() == cur) {
      path.pop_back();
    }
  }

  while (!path.empty()) {
    cout << path.front();
    path.pop_front();
    if (!path.empty()) {
      cout << " ";
    } else {
      cout << endl;
    }
  }
}