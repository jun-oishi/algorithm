#include <bits/stdc++.h>
using namespace std;

int main() {
  // char 型は''で囲む
  char c = 'c';
  // string 型は""で囲む
  string s = "string";
  // char型では標準入力を1文字ずつ受け取れる
  char d, e, f;
  cin >> d >> e >> f;
  cout << d << e << f << endl;
  // string型では1行まるごと受け取れる
  string text_in;
  getline(cin, text_in);

  // 文字列としての長さは.size()で取得する
  int size = s.size();
  cout << "size of s is" << size;
  // n文字目は.at(n)で取得、代入できる
  cout << "2nd char is" << s.at(1);
  s.at(3) = c;  // 代入できるのはchar型の値
  // リテラルについてメンバ関数を利用するときはsをつける
  cout << "size of `string` is"
       << "string"s.size();
  // 結合は+演算子でできる
  cout << s + s;
  // += も使える
  s += s;
  // char型とも結合できる
  s += c;

  // stringもcharも比較演算子が使える
  if (s == s + s) {
    cout << "strings are the same";
  }
  if (c > 'c') {  // 不等号は辞書順(0-9->A-Z->a-z)を比較する
    cout << "former is later";
  }
  // 1文字であってもstringとcharは比較できない
  // if ("s" != 'c') {
  //     cout << "cannot compare";
  // }
  if (s.at(0) == 'a') {  // .at(n)で取得した文字は可能
    cout << "string begins with `s`";
  }
}
