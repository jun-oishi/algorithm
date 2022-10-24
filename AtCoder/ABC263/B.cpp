#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> p(n-1);
  // 人iの祖先はp[i-2]
  for (int i=0; i<n-1; i++) {
    cin >> p[i];
  }

  int c = 0;
  while (n > 1) {
    c++;
    n = p[n-2];
  }
  cout << c << endl;
}
