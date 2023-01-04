#include <iostream>
using namespace std;

int main() {
  int s = 0;
  for (int i = 0; i < 10; i++) {
    int j = i * i;
    s += j;
    cout << "hello world  j:" << j << ", s :" << s << endl;
  }
}