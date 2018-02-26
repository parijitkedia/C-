#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <boost/optional.hpp>

using namespace std;
using namespace CGAL;
using namespace boost;

typedef Exact_predicates_exact_constructions_kernel K;
typedef K::Segment_2 S;
typedef K::Ray_2 R;
typedef K::Point_2 P;


double floor_to_double(const K::FT& x) {
  double a = floor(to_double(x));
  while (a > x) a -= 1;
  while (a+1 <= x) a += 1;
  return a; 
}

void replace_closest(R& ray ,optional<P>& closest, const P& point) {
  if(closest) {
    if (squared_distance(ray.source(), point) < squared_distance(ray.source(), *closest)) {
      closest = point;
    }
  } else {
    closest = point;
  } 
}

optional<P> solve(R ray, vector<S>& obstacles) {
  optional<P> closest;
  for (auto o: obstacles) {
    bool intersect = do_intersect(ray, o);
    if (intersect) {
      auto i = intersection(ray, o);
      if (const P* ip = get<P>(&*i)) 
        replace_closest(ray, closest, *ip);
      else if (const S* is = get<S>(&*i)) {
        replace_closest(ray, closest, (*is).source());
        replace_closest(ray, closest, (*is).target()); 
      } else { 
        exit(1); 
      } 
    } 
  }
  return closest;
}

int main() {
  cout << setiosflags(ios::fixed) << setprecision(0);
  while (true) {
    int n;
    cin >> n;
    if (n == 0)
      break;

    long x, y, a, b;
    cin >> x >> y >> a >> b;
    P p(x, y), q(a, b);
    R ray(p, q);
    vector<S> obstacles;

    for (int i = 0; i < n; ++i) {
      long fx, fy, tx, ty;
      cin >> fx >> fy >> tx >> ty;
      P f(fx, fy), t(tx, ty);
      S o(f, t);
      obstacles.push_back(o);
    }

    auto solution = solve(ray, obstacles);
    
    if (solution) {
      P& point = solution.get();
      long px = floor_to_double(point.x());
      long py = floor_to_double(point.y());
      cout << px << " " << py << endl;
    } else {
      cout << "no" << endl;
    }
  }
}