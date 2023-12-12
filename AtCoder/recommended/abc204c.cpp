#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 2000;
const int M_MAX = 2000;
int n, m;
int g[N_MAX + 1][N_MAX + 1];
int reachable[N_MAX + 1];

void dfs(int start) {
  if (reachable[start]) return;
  reachable[start] = 1;
  // cout << " " << start;
  for (int i = 1; i <= g[start][0]; i++) {
    dfs(g[start][i]);
  }
  return;
}

int main() {
  for (int i = 0; i <= N_MAX; i++) {
    g[i][0] = 0;
  }
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[a][0]++;
    g[a][g[a][0]] = b;
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) reachable[j] = 0;
    // cout << i << endl;
    dfs(i);
    for (int j = 1; j <= n; j++) {
      if (reachable[j]) ans++;
    }
    // cout << endl;
  }
  cout << ans << endl;
}