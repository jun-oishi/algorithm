#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> x(4);
  vector<int> y(4);
  for (int i = 0; i < 4; i++) {
    cin >> x[i] >> y[i];
  }

  string ans = "Yes";
  for (int i=0; i<4; i++) {
    int j = i+1;
    if (j==4) j=0;
    int dx1 = x[j] - x[i];
    int dy1 = y[j] - y[i];

    int k = j+1;
    if (k==4) k=0;
    int dx2 = x[k] - x[j];
    int dy2 = y[k] - y[j];

    int cross = dx1*dy2 - dx2*dy1;
    if (cross < 0) {
      ans = "No";
      break;
    }
  }
  cout << ans << endl;
}
