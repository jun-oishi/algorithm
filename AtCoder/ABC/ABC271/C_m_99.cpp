#include <bits/stdc++.h>
using namespace std;

// void show(vector<int> v) {
//   for (int i = 0; i < v.size(); i++) {
//     cout << v[i] << " ";
//   }
//   cout << endl;
// }

// void show(vector<bool> v) {
//   for (int i = 0; i < v.size(); i++) {
//     cout << v[i] << " ";
//   }
//   cout << endl;
// }

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<bool> can_read(n+1, false);
  int can_sell = 0; // 「売れる」巻の数
  for (int i = 0; i < n; i++) {
    if (a[i] > n) { // nより大きい巻を読むことはない
      can_sell++;
      continue;
    }
    if (can_read[a[i]]) { // ダブりの場合
      can_sell++;
    }
    can_read[a[i]] = true;
  }

  int min_lack = 1; // 読めない巻で最小のもの
  int max_have = n; // 持っている巻で最大のもの
  while (true) {
    while (can_read[min_lack]) {
      min_lack++;
    }
    while (!can_read[max_have]) {
      max_have--;
    }
    // cout << "can_read:";
    // show(can_read);
    // cout << "min_lack:" << min_lack << " max_have:" << max_have << " can_sell:" << can_sell << endl;
    if (can_sell >= 2) { // 「売れる」巻が2冊以上ある場合
      can_sell -= 2;
      can_read[min_lack] = true;
      continue;
    }
    // 直ちに交換できない場合大きい巻から「売れる」扱いにする
    if (min_lack > max_have) break; // 「大きい巻」がなければ終了
    can_read[max_have] = false;
    can_sell++;
  }

  cout << min_lack-1 << endl;
}