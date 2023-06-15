#include <bits/stdc++.h>
using namespace std;

int getTime(vector<string> &s, int n) {
  // iに揃えるのにかかる時間を求める
  int ssize = s.size();
  vector<int> order(ssize);
  vector<int> cnt(10, 0);
  int max = 0;
  for (int i=0; i<ssize; i++) {
    for (int j=0; j<10; j++) {
      if (s.at(i).at(j) == to_string(n).at(0)) {
        order.at(i) = cnt.at(j) * 10 + j;
        cnt.at(j)++;
      }
    }
    if (order.at(i) > max) max = order.at(i);
  }
  return max;
}

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i=0; i<n; i++) cin >> s.at(i);

  int mintime = -1;
  for (int i=0; i<=9; i++) {
    int time = getTime(s, i);
    if (time < mintime || mintime == -1) mintime = time;
  }
  cout << mintime << endl;
}