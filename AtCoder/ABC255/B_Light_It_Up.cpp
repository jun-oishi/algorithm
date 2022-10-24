#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(k), x(n), y(n);
  for (int i = 0; i < k; i++) cin >> a.at(i);
  for (int i = 0; i < n; i++) {
    cin >> x.at(i) >> y.at(i);
  }

  vector<double> min_dist(n, 1e7);
  for (int i = 0; i < n; i++) {
    int x_to = x.at(i), y_to = y.at(i);
    for (int j = 0; j < k; j++) {
      int x_from = x.at(a.at(j) - 1), y_from = y.at(a.at(j) - 1);
      double dx = x_to - x_from, dy = y_to - y_from;
      double dist = sqrt(dx * dx + dy * dy);
      if (dist < min_dist.at(i)) min_dist.at(i) = dist;
    }
  }
  double ans = 0;
  for (auto it = min_dist.begin(); it != min_dist.end(); it++) {
    if (ans < *it) ans = *it;
  }
  cout << fixed << setprecision(6) << ans << endl;
}