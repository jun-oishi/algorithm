#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> cards(n);
  for (int i=0; i<n; i++) cin >> cards[i];
  sort(cards.begin(), cards.end());
  int alice=0, bob=0;
  bool odd=true;
  for (auto it=cards.rbegin(); it != cards.rend(); it++) {
    if (odd) {
      alice += *it;
    } else {
      bob += *it;
    }
    odd = !odd;
  }
  cout << alice-bob << endl;
  return 0;
}