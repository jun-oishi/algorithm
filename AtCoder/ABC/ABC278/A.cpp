#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  queue<int> a;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.push(x);
  }
  for (int i = 0; i < k; i++) {
    a.pop();
    a.push(0);
  }

  cout << a.front();
  a.pop();
  while (!a.empty()) {
    cout << " " << a.front();
    a.pop();
  }
}