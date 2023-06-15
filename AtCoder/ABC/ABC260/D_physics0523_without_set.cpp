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

  // i+1の下にあるカードの数字-1
  vector<int> under(n, -1);
  // i+1が含まれる山のカードの全数(数字が見えているカードのみ、ほかは0にする)
  vector<int> pile(n, 0);
  // i+1が食べられるターン
  vector<int> ans(n, -1);
  // O(kn^2)
  for (int i=0; i<n; i++) {
    // cout << "p[" << i << "] = " << p[i] << ": ";
    if (k==1) {
      ans[p[i]-1] = i+1;
      continue;
    }
    bool new_pile = true;
    // p[i]-1より大きい添字から探索すれば良い
    // O(kn)
    // ↑これではおそすぎるがset::upper_bound なら O(log(n))
    for (int j=p[i]; j<n; j++) {
      if (pile[j] == 0) {
        continue;
      } else if (pile[j] < k-1)  {
        new_pile = false;
        // cout << "put on " << j+1 << endl;
        pile[p[i]-1] = pile[j] + 1;
        pile[j] = 0;
        under[p[i]-1] = j;
        break; // j
      } else {
        new_pile = false;
        pile[j] = 0;
        // cout << "eat " << p[i];
        ans[p[i]-1] = i+1;
        int to_eat = j;
        // O(k)
        for (int l=0; l<k-1; l++) {
          // cout << ", " << to_eat+1;
          ans[to_eat] = i+1;
          to_eat = under[to_eat];
          if (to_eat == -1) {
            break;
          }
        }
        // cout << endl;
        // cout << " => ans:" << vector2string(ans) << endl;
        break; // j
      }
    }
    if (new_pile) {
      // cout << "new pile" << endl;
      pile[p[i]-1] = 1;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
}
