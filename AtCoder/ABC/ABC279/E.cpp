#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;

int getS(int i) {
  vector<int> b;
  for (int j = 0; j <= n; j++) b.push_back(j);
  for (int k = 1; k <= m; k++) {
    if (k == i) continue;
    swap(b[a[k]], b[a[k] + 1]);
  }
  for (int j = 1; j <= n; j++) {
    if (b[j] == 1) return j;
  }
  return -1;
}

int main() {
  cin >> n >> m;
  a = vector<int>(m+1);
  for (int i = 1; i <= m; i++) cin >> a[i];

  for (int i = 1; i <= m; i++) {
    int s = getS(i);
    cout << s << endl;
  }
}