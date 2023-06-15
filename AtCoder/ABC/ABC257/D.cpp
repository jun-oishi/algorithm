#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> x, y, p;

// i->j に必要なsを返す
long long dist(int i, int j) {
  long long q = (abs(x[i] - x[j]) + abs(y[i] - y[j])) / p[i];
  long long r = (abs(x[i] - x[j]) + abs(y[i] - y[j])) % p[i];
  if (r) q++;
  return q;
}

// distがs以下の移動だけでcからすべてのジャンプ台が連結になるか
// O(n^2)
bool wfs(long long s, int c) {
  queue<int> que;
  vector<bool> checked(n, false);
  que.push(c);
  checked[c] = true;
  while (!que.empty()) {
    int i = que.front();
    que.pop();
    for (int j=0; j<n; j++) {
      if (checked[j]) continue;
      if (dist(i, j) <= s) {
        que.push(j);
        checked[j] = true;
      }
    }
  }
  for (int i=0; i<n; i++) {
    if (!checked[i]) return false;
  }
  true;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int xi, yi, pi;
    cin >> xi >> yi >> pi;
    x.push_back(xi);
    y.push_back(yi);
    p.push_back(pi);
  }

  long long left=0, right = 4e9;
  while (left < right) {
    long long mid = (left + right) / 2;
    for (int c=0; c<n; c++) {
      if (wfs(mid, c)) {
        right = mid;
        break;
      }
    }
    left = mid + 1;
  }
  cout << left << endl;
}