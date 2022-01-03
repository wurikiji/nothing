#include "adapter.hpp"

#include <utility>
#include <vector>

#include "point-and-line.hpp"
#include "vector-object.hpp"
#include "vector-rectangle.hpp"

using namespace std;
int main() {
  vector<shared_ptr<VectorObject>> vectorObjects{
      make_shared<VectorRectangle>(10, 10, 100, 100),
      make_shared<VectorRectangle>(30, 30, 60, 60)};
  for (auto& obj : vectorObjects) {
    for (auto& line : *obj) {
      LineToPointAdapter lpo{line};
      DrawPoints(lpo.begin(), lpo.end());
    }
  }
  return 0;
}