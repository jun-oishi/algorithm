#include <bits/stdc++.h>
using namespace std;


int main() {
  int n, m;
  cin >> n >> m;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (mp.find(a) == mp.end()) {
      mp[a] = 1;
    } else {
      mp[a]++;
    }
  }
  vector<pair<int,int>> vec;
  for (auto p : mp) {
    vec.push_back(make_pair(p.first, p.second));
  }
  int k = vec.size(); // 手札の数の種類の数

  if (k == m) {
    cout << 0 << endl;
    return 0;
  }
  int end; // endの後にカードを出せないようなendを探す
  for (int i = 0; i < k; i++) {
    if (vec.at((i+1)%k).first != (vec.at(i).first+1)%m) { // k < mならこれを満たすiが必ず存在する
      end = i;
      break;
    }
  }

  int whole_sum = 0;
  for (auto p: vec) whole_sum += p.first * p.second;
  // cout << whole_sum << endl;
  vector<int> sum(k);
  for (int i = 0; i < k; i++) {
    int j = (end - i + k) % k; // jを最初に出す場合を考える
    if (vec.at((j+1)%k).first == (vec.at(j).first+1)%m) { // v[(j+1)%k]を次に出せるならそれを参照して結果を求める
      sum.at(j) = sum.at((j+1)%k);
    } else { // 次がないなら全体の和を参照する
      sum.at(j) = whole_sum;
    }
    sum.at(j) -= vec.at(j).first * vec.at(j).second; // jを出すのでjのカードを引く
    // cout << j << ":" << sum.at(j) << endl;
  }

  int ans = whole_sum;
  for (int s: sum) ans = min(ans, s);
  cout << ans << endl;
}