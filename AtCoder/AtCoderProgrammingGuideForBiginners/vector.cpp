#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> u = {0, 1, 2, 3};
  vector<int> v(3); // {0, 0, 0}が入る
  vector<int> w(3, 4); //  (要素数, 初期値)で{4, 4, 4}が入る
  // 要素数、各要素へのアクセスはstringと同じ
  cout << "u has" << u.size() << "elements";
  cout << v.at(0);
  cin >> w.at(2);
  // varname[i]でもアクセスできる(がout_of_rangeエラーが出ないらしい)
  cin >> w[3];
  // push_back で末尾に要素を追加できる
  u.push_back(4); // -> u = {0, 1, 2, 3, 4}
  // pop_back で末尾の要素を削除できる
  u.pop_back(); // -> u = {0, 1, 2, 3}
  // == で配列`変数`同士の比較(全要素の一致)ができる
  if (u == v) cout << "each element of u, v is all same";
  // u == {0, 1, 2, 3}; // リテラルとの比較は不可
}
