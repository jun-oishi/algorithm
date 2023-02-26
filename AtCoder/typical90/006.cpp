#include<iostream>
using namespace std;

int N, K;
const int L = 26; // 文字の数

int main() {
  cin >> N >> K;
  char S[N];
  for (int i=0; i<N; i++) cin >> S[i];

  // c[i][j] = i文字目またはそれより右の文字`j`で最も左のもののインデックス
  int c[N+1][L];
  for (int j=0; j<L; j++) c[N][j] = N;
  for (int i=N-1; i>=0; i--) {
    for (int j=0; j<L; j++) {
      if ((int)(S[i]-'a')==j) c[i][j] = i;
      else c[i][j] = c[i+1][j];
    }
  }

  // 可能な次のインデックスで最小のもの
  int cur = 0;
  // k_rest:これから選ぶ必要がある文字の数
  for (int k_rest=K; k_rest>0; k_rest--) {
    for (int j=0; j<L; j++) {
      if (N-c[cur][j] > k_rest-1) {
        cur = c[cur][j]+1;
        cout << (char)('a'+j);
        break;
      }
    }
  }

  cout << endl;

  return 0;
}