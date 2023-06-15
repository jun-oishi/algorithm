#include <bits/stdc++.h>
using namespace std;

using si = set<int>;
using tablestate = unordered_map<int, si>;

string flatten_set(si s) {
  string ret = "{";
  for (int i: s) {
    ret += to_string(i) + ", ";
  }
  ret += "}";
  return ret;
}

string vector2string(vector<int> v) {
  string ret = "[";
  for (int i: v) {
    ret += to_string(i) + ", ";
  }
  ret += "]";
  return ret;
}

void show_map(tablestate tbl) {
  for (auto it = tbl.begin(); it != tbl.end(); it++) {
    cout << it->first << " => " << flatten_set(it->second) << endl;
  }
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  for (int i = 0; i < n; i++) cin >> p[i];

  // -一番上のカードの数字 => {山に含まれるカードそれぞれの数字}のmap
  // XXX : キーは降順に整列されるので-1倍しておく
  //      ↑偽
  tablestate tbl;
  vector<int> ans(n, -1);
  for (int i = 0; i < n; i++) {
    cout << "p[" << i << "] = " << p[i] << endl;
    bool flg = false;
    for (auto it = tbl.begin(); it != tbl.end(); it++) {
      if (it->first < -p[i]) {
        // より大きい数字がある場合
        flg = true;
        si s = it->second;
        if (s.size() < k-1) {
          // 山がk-1枚未満なら重ねる
          s.insert(p[i]);
          tbl[-p[i]] = s;
        } else {
          // 山がk-1枚なら食べる
          s.insert(p[i]);
          for (int j: s) {
            ans[-j-1] = i+1;
          }
          cout << "s:" << flatten_set(s) << " ans:" << vector2string(ans) << endl;
        }
        // いずれにしてもit->firstが見えている山はなくなる
        tbl.erase(it);
        break;
      }
    }
    if (!flg) {
      si s;
      s.insert(-p[i]);
      tbl[-p[i]] = s;
    }
    show_map(tbl);
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
}
