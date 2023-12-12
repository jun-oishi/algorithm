#include <bits/stdc++.h>

using namespace std;

int n, m;
int l[200000];

int compute(int w) {
  int cur = 0;
  int lines = 1;
  for (int i = 0; i < n; i++) {
    cur += 1 + l[i];
    if (cur > w) {
      if (l[i] > w) {
        lines = -1;
        break;
      }
      cur = l[i];
      lines++;
    }
  }
  return lines;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> l[i];
}