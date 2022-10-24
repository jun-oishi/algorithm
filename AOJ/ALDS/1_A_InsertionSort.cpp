#include <bits/stdc++.h>
using namespace std;

void show(vector<int> sorted, queue<int> q) {
  for (int i: sorted) cout << i << " ";
  while (!q.empty()) {
    cout << q.front();
    q.pop();
    if (!q.empty()) cout << " ";
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  queue<int> q;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    q.push(a);
  }

  vector<int> sorted(1, q.front());
  q.pop();
  show(sorted, q);
  while (!q.empty()) {
    int target = q.front();
    q.pop();
    bool inserted = false;
    for (int i = 0; i < sorted.size(); i++) {
      if (target < sorted[i]) {
        sorted.insert(sorted.begin() + i, target);
        inserted = true;
        break;
      }
    }
    if (!inserted) sorted.push_back(target);

    show(sorted, q);
  }
}