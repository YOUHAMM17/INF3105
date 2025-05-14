/*
  UQAM / Département d'informatique
  INF3105
  Laboratoire 1
*/

#include <iostream>
#include <limits>

#include "point.h"

int main() {
  int nb;
  std::cin >> nb;

  Point* points = new Point[nb];
  for (int i = 0; i < nb; i++) std::cin >> points[i];

  double distance_minimal = std::numeric_limits<double>::infinity();
  for (int a = 0; a < nb; a++) {
    for (int b = a + 1; b < nb; b++) {
      double d = points[a].distance(points[b]);
      if (d < distance_minimal) distance_minimal = d;
    }
  }

  std::cout << distance_minimal << std::endl;

  delete[] points;
  return 0;
}
