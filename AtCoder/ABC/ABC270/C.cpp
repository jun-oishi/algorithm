#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

void showq(queue<int> q) {
  for (int i = 0; i < q.size(); i++) {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
}

void showvi(vi v) {
  if (v.size() == 0) {
    cout << "{}" << endl;
    return;
  }
  cout << "{" << v[0];
  for (int i = 1; i < v.size(); i++) {
    cout << "," <<v[i];
  }
  cout << "}";
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

  queue<int> q;
  q.push(x);
  vector<bool> seen(n+1, false);
  seen[x] = true;
  vvi paths(n+1, vi()); // paths[i] = {x, ..., i}
  paths[x].push_back(x);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int next : g[cur]) {
      if (seen[next]) continue;
      seen[next] = true;
      vi new_path = paths[cur];
      new_path.push_back(next);
      // showvi(new_path);
      // cout << endl;
      paths[next] = new_path;
      if (next == y) {
        q = queue<int>(); // whileも抜けて良い
        break;
      }
      q.push(next);
    }
  }

  vi ans = paths[y];
  cout << ans[0];
  for (int i = 1; i < ans.size(); i++) {
    cout << " " << ans[i];
  }
  cout << endl;
}