#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
using Mat = vector<vector<long long>>;
using Vec = vector<long long>;

const int mod = 1000000007;

template <class T>
void show(vector<T> v) {
  for (int i = 0; i < v.size(); i++) {
    if (i) cout << " ";
    cout << v[i];
  }
  cout << endl;
}

int log(long long v, int r) {
  int res = 1;
  while (v > 0) {
    v /= r;
    res++;
  }
  return res;
}

int log2(long long v) { return log(v, 2); }

// O(n^3)
Mat product(Mat a, Mat b) {
  Mat res = Mat(a.size(), Vec(b[0].size(), 0));
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b[0].size(); j++) {
      for (int k = 0; k < b.size(); k++) {
        res[i][j] += a[i][k] * b[k][j];
        res[i][j] %= mod;
      }
    }
  }
  return res;
}

// O(n^2)
Vec product(Mat A, Vec b) {
  Mat B(b.size(), Vec(1, 0));
  for (int i=0; i<b.size(); i++) B[i][0] = b[i];
  Mat P = product(A, B);
  Vec res(P.size(), 0);
  for (int i=0; i<P.size(); i++) res[i] = P[i][0];
  return res;
}

// O(n)
Mat unit(int n) {
  Mat res = Mat(n, Vec(n, 0));
  for (int i = 0; i < n; i++) res[i][i] = 1;
  return res;
}

// O(n^3 log p)
Mat pow(Mat a, long long p) {
  Mat res = unit(a.size());
  Mat squared = a;
  while (p > 0) {
    if (p % 2) res = product(res, squared);
    squared = product(squared, squared);
    p /= 2;
  }
  return res;
}

// O(nbk)の解法
int solve_nbk(long long n, int b, int k, vector<int> c) {
  // dp[i][j]: i桁の数でbで割ったあまりがjになる数の個数
  vector<vector<int>> dp(n+1, vector<int>(b, 0));
  dp[0][0] = 1;
  for (int i=1; i<=n; i++) {
    for (int j=0; j<b; j++) {
      for (int l=0; l<k; l++) {
        // 末尾にc[l]を追加したときの余り
        int next = (j * 10 + c[l]) % b;
        dp[i][next] = (dp[i][next] + dp[i-1][j]) % mod;
      }
    }
  }
  return dp[n][0];
}

// O(b^3 log n) の解法
int solve_b3logn(long long n, int b, int k, vector<int> c) {
  // dp[i+1][:] = A * dp[i][:] となる行列A
  Mat A = Mat(b, Vec(b, 0));
  for (int i=0; i<b; i++) {
    for (int j=0; j<k; j++) {
      int next = (i*10 + c[j]) % b;
      A[next][i]++;
    }
  }
  // dp[0][:]にあたる配列
  Vec ini(b, 0);
  ini[0] = 1;
  Mat An = pow(A, n); // O(b^3 log n)
  // dp[n][:]にあたる配列
  Vec fin = product(An, ini);

  return fin[0];
}

// O(b^2 log n)の解法
int solve_b2logn(long long n, int b, int k, vector<int> c) {
  int log_n = log2(n);

  // power10[i] = 10^(2^i) % b
  vector<int> power10(log_n+1);
  power10[0] = 10 % b;
  for (int i=0; i<log_n; i++) power10[i+1] = (power10[i]*power10[i]) % b;
  // show<int>(power10);

  // dp2[i][j] := dp[2^i][j] = 2^i桁でbで割った余りがjの場合の数
  vector<Vec> dp2(log_n+1, Vec(b, 0));
  for (int i=0; i<k; i++) dp2[0][c[i]%b]++;
  // cout << "1 : ";
  // show<long long>(dp2[0]);
  for (int i = 0; i < log_n; i++) {
    for (int l = 0; l < b; l++) {
      for (int m = 0; m < b; m++) {
        // 余りがlの2^i桁の10^(2^i)倍と余りがmの2^i桁の和の余りを考える
        int next = (l * power10[i] + m) % b;
        dp2[i+1][next] += dp2[i][l] * dp2[i][m];
        dp2[i+1][next] %= mod;
      }
    }
    // cout << (1 << i+1) << " : ";
    // show<long long>(dp2[i+1]);
  }

  // ans[i][j] := dp[(nの2進下i桁)][j]
  vector<Vec> ans(log_n+1, Vec(b, 0));
  ans[0][0] = 1;
  // long long debug = 0;
  for (int i=0; i<log_n; i++) {
    if ((n & (1LL << i)) != 0LL) { // nの2進i桁目が1の場合
      // debug += (1 << i);
      // cout << debug << " : ";
      // 2^i桁部分(dp2[i])を使ってans[i+1]を構成する
      for (int l=0; l<b; l++) {
        for (int m=0; m<b; m++) {
          int next = (l*power10[i] + m) % b;
          ans[i+1][next] += ans[i][l] * dp2[i][m];
          ans[i+1][next] %= mod;
        }
      }
      // show<long long>(ans[i+1]);
    } else { // nが2^iを含まないとき
      // 2^i桁部分は使われないのでa[i+1]=a[i]
      for (int l=0; l<b; l++) ans[i+1][l] = ans[i][l];
    }
  }
  // cout << endl;

  return ans[log_n][0];
}

int main() {
  long long n;
  int b, k;
  vector<int> c;

  cin >> n >> b >> k;
  c.resize(k);
  for (int i = 0; i < k; i++) cin >> c[i];

  int ans = solve_b2logn(n, b, k, c);

  cout << ans << endl;

  return 0;
}