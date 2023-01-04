#include <iostream>
#include <algorithm>
#include <map>

const int MAX_W = 1e4;

void copy(int *from, int *to, int n) {
  for (int i = 0; i < n; i++) {
    to[i] = from[i];
  }
}

int sum(int *a, int n) {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += a[i];
  }
  return ans;
}

int solve(int *W, int n, int min_w) {
  int sorted[n];
  copy(W, sorted, n);
  std::sort(sorted, sorted + n);
  std::map<int, int> dist;
  for (int i = 0; i < n; i++) dist[sorted[i]] = i;

  bool checked[n];
  int ans = 0;
  for (int i = 0; i < n; i++) checked[i] = false;
  for (int i = 0; i < n; i++) {
    if (checked[i]) continue; else checked[i] = true;
    int cycle[n];
    int cycle_n = 1;
    int cycle_min = MAX_W;
    cycle[0] = W[i];
    for (int j = dist[W[i]]; W[j] != cycle[0]; j = dist[W[j]]) {
      cycle[cycle_n++] = W[j];
      cycle_min = std::min(cycle_min, W[j]);
      checked[j] = true;
    }

    if (cycle_n == 1) continue;

    int in_cycle_cost = sum(cycle, cycle_n) + (cycle_n - 2) * cycle_min;
    int beyond_cycle_cost = sum(cycle, cycle_n) + cycle_min + (cycle_n + 1) * min_w;
    ans += std::min(in_cycle_cost, beyond_cycle_cost);
  }

  return ans;
}

int main() {
  int n;
  std::cin >> n;
  int W[n];
  int min_w = MAX_W;
  for (int i = 0; i < n; i++) {
    std::cin >> W[i];
    if (W[i] < min_w) min_w = W[i];
  }

  int ans = solve(W, n, min_w);
  std::cout << ans << std::endl;
}