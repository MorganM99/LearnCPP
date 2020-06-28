#include <algorithm>
#include <iostream>
#include <vector>

class Point {
private:
  int m_x = 0;
  int m_y = 0;
  int m_z = 0;

public:
  Point (int x = 0, int y = 0, int z = 0) : m_x (x), m_y (y), m_z (z) {}

  friend std::ostream& operator<< (std::ostream& out, const Point& p) {
    out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
    return out;
  }
};

class Shape {
public:
  Shape() {}

  virtual std::ostream& print (std::ostream& out) const = 0;
  friend std::ostream& operator<< (std::ostream& out, const Shape& s) {
    return s.print (out);
  }
  virtual ~Shape() {}
};

class Triangle : public Shape {
private:
  Point m_point1;
  Point m_point2;
  Point m_point3;

public:
  Triangle (const Point& point1, const Point& point2, const Point& point3) :
      m_point1 {point1}, m_point2 {point2}, m_point3 {point3} {}
  virtual std::ostream& print (std::ostream& out) const override {
    out << "Triangle (" << m_point1 << ", " << m_point2 << ", " << m_point3
        << ")"
        << "\n";
    return out;
  }
};

class Circle : public Shape {
private:
  Point m_centre;
  int m_radius;

public:
  Circle (const Point& centre, int radius = 1) :
      m_centre {centre}, m_radius {radius} {}
  virtual std::ostream& print (std::ostream& out) const override {
    out << "Circle (" << m_centre << ", "
        << "radius " << m_radius << ")"
        << "\n";
    return out;
  }
  int getRadius() const { return m_radius; }
};

int getLargestRadius (const std::vector<Shape*>& v) {
  int largestRadius {0};
  for (auto const element : v) {
    if (Circle* c = dynamic_cast<Circle*> (element)) {
      if (c->getRadius() > largestRadius) { largestRadius = c->getRadius(); }
    }
  }
  return largestRadius;
}
int main() {
  std::vector<Shape*> v;
  v.push_back (new Circle (Point (1, 2, 3), 7));
  v.push_back (
      new Triangle (Point (1, 2, 3), Point (4, 5, 6), Point (7, 8, 9)));
  v.push_back (new Circle (Point (4, 5, 6), 3));

  for (auto const element : v) {
    std::cout << *element;
  }
  std::cout << "The largest radius is: " << getLargestRadius (v) << '\n';

  for (auto const element : v) {
    delete element;
  }

  return 0;
}