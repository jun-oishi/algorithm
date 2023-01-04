#include <cstdio>
#include <cmath>
#include <utility>

using xy = std::pair<double, double>;
using polar = std::pair<double, int>; // r, theta[deg]

void showXY(xy p) {
  printf("%f %f\n", p.first, p.second);
}

xy add(xy from, polar dist) {
  double x = from.first + dist.first * cos(dist.second * M_PI / 180);
  double y = from.second + dist.first * sin(dist.second * M_PI / 180);
  return std::make_pair(x, y);
}

polar divide(polar dist, int p) {
  return std::make_pair(dist.first / p, dist.second);
}

polar rotate(polar dist, int theta) {
  return std::make_pair(dist.first, dist.second + theta);
}

void draw(int depth, xy ini, polar dist) {
  if (depth == 0) return;
  polar divided = divide(dist, 3);
  xy s = add(ini, divided);
  xy t = add(s, rotate(divided, 60));
  xy u = add(t, rotate(divided, -60));
  draw(depth - 1, ini, divided);
  showXY(s);
  draw(depth - 1, s, rotate(divided, 60));
  showXY(t);
  draw(depth - 1, t, rotate(divided, -60));
  showXY(u);
  draw(depth - 1, u, divided);
  return;
}

int main() {
  int n;
  scanf("%d", &n);
  xy ini = std::make_pair(0, 0);
  polar dist = std::make_pair(100, 0);
  showXY(ini);
  draw(n, ini, dist);
  showXY(add(ini, dist));
}