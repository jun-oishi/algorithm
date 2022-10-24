#include <bits/stdc++.h>
using namespace std;

// 各要素は[i,時刻Tiにいる頂点,時刻Tiまでの総得点]のタプル
using state = tuple<int,int,long long>;

int main() {
  int n;
  cin >> n;
  vector<int> t(n);
  vector<int> x(n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i] >> x[i] >> a[i];
  }
  int t_max = t[n-1];

  stack<state> st;
  st.push(state(-1,0,0));

  int ans = 0;
  while (st.size() != 0) {
    state s = st.top();
    st.pop();
    int i = get<0>(s);
    int x_now = get<1>(s);
    int a_now = get<2>(s);
    if (a_now > ans) ans = a_now;

    // i+!番目以降が捕まえられるか調べて状態を追加する
    for (int j = i+1; j < n; j++) {
      int dx = abs(x[j] - x_now);
      int dt = t[j] - t[i];
      if (dx <= dt) {
        // j番目を捕まえることが可能ならその状態をスタックに積む
        st.push(state(j,x[j],a_now+a[j]));
      }
    }
  }
  cout << ans << endl;
}
