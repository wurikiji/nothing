#ifndef _ADAPTER_HPP
#define _ADAPTER_HPP
#include <vector>

#include "point-and-line.hpp"
using namespace std;
// Enhancement: Need to implement cache
struct LineToPointAdapter {
  typedef vector<Point> Points;
  LineToPointAdapter(Line& line) {
    // eager transform
    int left = min(line.start.x, line.end.x);
    int right = max(line.start.x, line.end.x);
    int top = min(line.start.y, line.end.y);
    int bottom = max(line.start.y, line.end.y);
    int dx = right - left;
    int dy = bottom - top;

    if (dx == 0) {
      // vertical line
      for (int y = top; y <= bottom; ++y) {
        points.emplace_back(Point{left, y});
      }
    } else if (dy == 0) {
      for (int x = left; x <= right; ++x) {
        points.emplace_back(Point{x, top});
      }
    }
  }

  virtual Points::iterator begin() { return points.begin(); }
  virtual Points::iterator end() { return points.begin(); }

 private:
  Points points;
};
#endif