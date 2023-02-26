#include<iostream>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

double angleAdd(double a, double b) {
  double res = a+b;
  if (a+b > 180) res -= 360;
  if (a+b < -180) res += 360;
  return res;
}

double angleDiff(double a, double b) {
  double res = abs(a-b);
  if (res > 180) res = 360 - res;
  return res;
}

int main() {
  int N;
  cin >> N;
  int X[N], Y[N];
  for (int i=0; i<N; i++) cin >> X[i] >> Y[i];

  double ans=0;
  for (int i=0; i<N; i++) {
    vector<double> arg(N);
    for (int j=0; j<N; j++) {
      if (j==i) continue;
      arg[j] = atan2(Y[j]-Y[i], X[j]-X[i]) *180/M_PI;
    }
    arg[i] = i==0 ? arg[1] : arg[0];
    sort(arg.begin(), arg.end());


    decltype(arg)::iterator it;
    for (int j=0; j<N; j++) {
      double needle = angleAdd(arg[j], 180);
      int idx1 = lower_bound(arg.begin(), arg.end(), needle) - arg.begin();
      idx1 %= arg.size();
      int idx2 = (idx1 + arg.size() - 1) % arg.size();
      ans = max({ans, angleDiff(arg[j], arg[idx1]), angleDiff(arg[j], arg[idx2])});
    }
  }

  cout << setprecision(9) << ans << endl;

  return 0;
}