#ifndef _VECTOR_OBJECT_HPP
#define _VECTOR_OBJECT_HPP
#include <vector>

struct VectorObject {
  // use iterator instead of vector itself
  virtual std::vector<Line>::iterator begin() = 0;
  virtual std::vector<Line>::iterator end() = 0;
};
#endif