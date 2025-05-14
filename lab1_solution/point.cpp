/************************************************
  Laboratoire 1
  INF3105 | Structures de données et algorithmes
  UQAM | Département d'informatique
  Source: http://cria2.uqam.ca/INF3105/lab1/
*************************************************/

#include "point.h"

#include <cassert>
#include <cmath>

Point::Point(const Point& point) : x(point.x), y(point.y) {}

Point::Point(double _x, double _y) : x(_x), y(_y) {}

double Point::distance(const Point& point) const {
  double dx = x - point.x, dy = y - point.y;
  return sqrt(dx * dx + dy * dy);
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
  os << "(" << point.x << "," << point.y << ")";
  return os;
}

std::istream& operator>>(std::istream& is, Point& point) {
  char po, vir, pf;
  is >> po;
  if (is) {
    is >> point.x >> vir >> point.y >> pf;
    assert(po == '(');
    assert(vir == ',');
    assert(pf == ')');
  }
  return is;
}
