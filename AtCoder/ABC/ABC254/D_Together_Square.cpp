#include <bits/stdc++.h>
using namespace std;

int getLargestSquareDivider(int n) {
  int ans = 1;
  for (int i=1; i*i <= n; i++) {
    if (n % (i*i) == 0) ans = i*i;
  }
  return ans;
}

int main() {
  int n;
  cin >> n;

  int ans = 0;
  for (int i=1; i<=n; i++) {
    int k = i / getLargestSquareDivider(i);
    for (int j=1; j*j*k<=n; j++) {
      ans++;
    }
  }

  cout << ans << endl;
}