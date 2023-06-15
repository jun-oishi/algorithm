#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> x(n), b(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < m; i++) {
    int ci, yi;
    cin >> ci >> yi;
    b[ci-1] = yi;
  }

  // s[i] = i+1までカウンタを増やしたときにもらえる総額の最大
  vector<long long> s(n, 0);
  // O(n^2)
  for (int i=0; i<n; i++) {
    for (int j=0; j<=i; j++) {
      s[i] += b[j];
    }
    cout << "simple s[" << i << "] : " << s[i] << endl;
    for (int j=0; j<i; j++) {
      if (i-j-2 < 0) continue;
        // j+1手で増やす->戻す->i+1-(j+2)手で増やす との比較
      if (s[i] < s[j] + s[i-j-2] - x[j+1]) {
        s[i] = s[j] + s[i-j-2];
        cout << "s[" << j << "] = " << s[j];
        cout << ", s[" << i-j-2 << "] = " << s[i-j-1];
        cout << " -> new s[" << i << "] : " << s[i] << endl;
      }
    }
  }

  cout << s[n-1] << endl;
}
