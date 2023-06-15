#include <bits/stdc++.h>
using namespace std;

// クリア回数d, 経過時間time, 最高ステージmax_s
using state = tuple<int, int, int>;

int n, x;
vector<int> a, b;

stack<state> next(state s, stack<state> &st) {
  stack<state> ret;
  int next_d = get<0>(s) + 1;
  int time = get<1>(s);
  int max_s = get<2>(s);
  // すでにクリア済みのステージを再度クリアする場合
  for (int i = 0; i < max_s; i++) {
    ret.push(make_tuple(next_d, time+a[i], max_s));
  }
  // 新しいステージをクリアする場合
  ret.push(make_tuple(
    next_d, time+a[max_s+1]+b[max_s+1], max_s+1
  ));
  return ret;
}



int main() {
  cin >> n, x;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
}