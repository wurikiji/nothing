#ifndef _POINT_AND_LINE_HPP
#define _POINT_AND_LINE_HPP

#include <vector>

struct Point {
  int x, y;
};

struct Line {
  Point start, end;
};

// Unfortunately, we have a draw function taking points only.
void DrawPoints(std::vector<Point>::iterator start,
                std::vector<Point>::iterator end) {
  for (auto i = start; i != end; ++i) {
    // Draw point;
  }
}
#endif