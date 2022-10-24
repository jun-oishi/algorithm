#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

// int depth = 0;

void dfs(int to, deque<int> &path, vector<bool> &visited, vvi &g) {
  if (path.back()==to) return;
  int cur = path.back();
  for (int next: g[cur]) {
    if (visited[next]) continue;
    // depth++;
    // for (int i=0; i<depth; i++) cout << " ";
    // cout << cur << " -> " << next << endl;
    visited[next] = true;
    path.push_back(next);
    if (next == to) {
      return;
    }
    dfs(to, path, visited, g);
  }
  if (path.back() != to) {
    // depth--;
    path.pop_back();
  }
  return;
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

  vector<bool> visited(n+1, false);
  visited[x] = true;
  deque<int> path = {x};

  dfs(y, path, visited, g);

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