#include <bits/stdc++.h>
using namespace std;

int ms_sum(multiset<int> ms) {
  int sum = 0;
  for (auto i : ms) {
    sum += i;
  }
  return sum;
}

// 場にfieldがあり手札がhandsのときのあり得る結果をresultに加える
void dfs(int field, multiset<int> &hands, set<int> &result, int m, int depth) {
  if (hands.size() == 0) {
    result.insert(0);
    return;
  }
  for (auto i: hands) {
    if (field == i || (field+1) % m == i) {
      multiset<int> next_hands = hands;
      next_hands.erase(next_hands.find(i));
      dfs(i, next_hands, result, m, depth+1);
    }
  }
  result.insert(ms_sum(hands));
}

int main() {
  int n, m;
  cin >> n >> m;
  multiset<int> hands;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    hands.insert(a);
  }

  set<int> result;
  result.insert(ms_sum(hands));
  for (auto i : hands) {
    multiset<int> next_hands = hands;
    next_hands.erase(next_hands.find(i));
    dfs(i, next_hands, result, m, 0);
  }
  cout << *result.begin() << endl;
}