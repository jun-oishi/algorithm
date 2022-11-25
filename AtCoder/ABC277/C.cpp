#include <bits/stdc++.h>
using namespace std;
using ll = long long;


// ini から移動可能な階すべてのベクトルをcan_gotoに格納する
void dfs(ll ini, map<int, set<int>> &l, set<int> &can_goto) {
  set<int> next = l[ini];
  for (auto i : next) {
    if (can_goto.find(i) == can_goto.end()) {
      can_goto.insert(i);
      dfs(i, l, can_goto);
    }
  }
}

int main() {
  ll n;
  cin >> n;
  map<int, set<int>> l;
  for (ll i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    if (l.count(a) > 0) {
      l[a].insert(b);
    } else {
      set<int> tmp;
      tmp.insert(b);
      l[a] = tmp;
    }
    if (l.count(b) > 0) {
      l[b].insert(a);
    } else {
      set<int> tmp;
      tmp.insert(a);
      l[b] = tmp;
    }
  }

  set<int> can_goto;
  can_goto.insert(1);
  dfs(1, l, can_goto);
  cout << *can_goto.rbegin() << endl;
}