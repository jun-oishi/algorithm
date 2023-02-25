#include<iostream>
#include<string>
using namespace std;

int n;

void search(string item, int opened, int closed) {
  if (closed == n/2) cout << item << endl;
  if (opened < n/2) search(item + "(", opened + 1, closed);
  if (opened > closed) search(item + ")", opened, closed + 1);
  return;
}

int main() {
  cin >> n;

  if (n % 2 == 0) {
    search("", 0, 0);
  } else {
    cout << endl;
  }

  return 0;
}