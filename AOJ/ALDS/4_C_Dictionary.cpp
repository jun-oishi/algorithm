#include <cstdio>
#include <string>
using namespace std;

// 収容できる文字列はA,T,C,Gからなる12文字以下の文字列とする
struct Dict {
  static const int M = 1 << 16;
  string set[M] = {""};
  void insert(string key) {
    if (this->find(key)) return;
    int i = 0;
    int h = this->hash(key, i);
    if (this->set[h] == "") {
      this->set[h] = key;
    } else {
      while (this->set[h] != "") {
        h = this->hash(key, i++);
      }
      this->set[h] = key;
    }
  }

  bool find(string needle) {
    int i = 0;
    int h = this->hash(needle, i);
    while (this->set[h] != "") {
      if (this->set[h] == needle) {
        return true;
      }
      h = this->hash(needle, i++);
    }
    return false;
  }

 private:
  int hash(string str, int i = 0) {
    int h0 = 0;
    int size = str.size();
    for (int i = 0; i < size; i++) {
      char c = str[i];
      int tmp;
      if (c == 'A') {
        tmp = 0;
      } else if (c == 'T') {
        tmp = 1;
      } else if (c == 'C') {
        tmp = 2;
      } else if (c == 'G') {
        tmp = 3;
      }
      h0 = (h0 << 2) | tmp;
    }
    return (h0 % this->M + i * (1 + (h0 % (this->M - 1)))) % this->M;
  }

};

int main() {
  int n;
  scanf("%d", &n);
  Dict dict;
  for (int i = 0; i < n; i++) {
    char command[7], key[13];
    scanf("%s %s", command, key);
    if (command[0] == 'i') {
      dict.insert(key);
    } else {
      if (dict.find(key)) {
        printf("yes\n");
      } else {
        printf("no\n");
      }
    }
  }
}