#ifndef ALDS_RECURSIVE_1_5_C_KOCH_CURVE_H_INCLUDED
#define ALDS_RECURSIVE_1_5_C_KOCH_CURVE_H_INCLUDED

#include <vector>
#include <string>
#include <math.h>
#include <cmath>
#include <limits>

namespace alds { namespace recursive {

struct Point { double x, y; };

bool operator==(const Point &l, const Point &r) {
  return (
    std::floor(l.x * 1000) == std::floor(r.x * 1000)
    && std::floor(l.y * 1000) == std::floor(r.y * 1000)
  );
}

void koch(int n, Point a, Point b, std::vector<Point> &result) {
  if (n == 0) return;
  Point s, t, u;
  double th = M_PI * 60.0 / 180.0;

  s.x = (2.0 * a.x + 1.0 * b.x) / 3.0;
  s.y = (2.0 * a.y + 1.0 * b.y) / 3.0;
  t.x = (1.0 * a.x + 2.0 * b.x) / 3.0;
  t.y = (1.0 * a.y + 2.0 * b.y) / 3.0;
  u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
  u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

  koch(n - 1, a, s, result);
  result.push_back(Point{s.x, s.y});
  koch(n - 1, s, u, result);
  result.push_back(Point{u.x, u.y});
  koch(n - 1, u, t, result);
  result.push_back(Point{t.x, t.y});
  koch(n - 1, t, b, result);
}

std::vector<Point> calculate_koch(int n, Point a, Point b) {
  std::vector<Point> result;

  result.push_back(a);
  koch(n, a, b, result);
  result.push_back(b);

  return result;
}

} /* namespace recursive */
} /* namespace alds */

#endif /* ifndef ALDS_RECURSIVE_1_5_C_KOCH_CURVE_H_INCLUDED */
