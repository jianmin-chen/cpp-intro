#include <iostream>
#include <math.h>
#include <vector>
#include <stdexcept>

// function declaration
int add(int x, int y);
int subtract(int x, int y);
int multiply(int x, int y);
int divide(int x, int y);

// function definition
int add(int x, int y)
{
  return x + y;
}

int subtract(int x, int y) {
  return x - y;
}

int multiply(int x, int y) {
  return x * y;
}

int divide(int x, int y) {
  return x / y;
}

class Circle {
public:
  float radius;

  Circle(float radius) {
    this->radius = radius;
  }

  float area() {
    return M_PI * radius * radius;
  }
};

class Point {
public:
  double x;
  double y;

  Point(double x, double y) {
    this->x = x;
    this->y = y;
  }

  Point() {
    this->x = 0;
    this->y = 0;
  }

  float distance_to_origin() {
    return sqrt(x * x + y * y);
  }

  float distance_to_point(Point other) {
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
  }
};

class Line {
public:
  Point p1;
  Point p2;
  
  Line(Point p1, Point p2) {
    this->p1 = p1;
    this->p2 = p2;
  }

  float length() {
    return p1.distance_to_point(p2);
  }

  float distance_to_point(Point p) {
    // Returns the distance between the line and the point
    float p1_distance = p1.distance_to_point(p);
    float p2_distance = p2.distance_to_point(p);
    return std::min(p1_distance, p2_distance);
  }
};

class Triangle {
public:
  Point p1;
  Point p2;
  Point p3;

  Triangle(Point p1, Point p2, Point p3) {
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
  }

  float area() {

  }
};

class Polygon {
public:
  std::vector<Point> vertices;

  Polygon(std::vector<Point> vertices) {
    if (vertices.size() < 4) throw std::invalid_argument("Given vertices must be of size 4 or more");
    this->vertices = vertices;
  }

  float area() {
    float result = 0;
    int triangles = vertices.size() - 2;
    // Three triangles from last vertex in vertices
    return result;
  }

  float perimeter() {
    float result = 0;
    // Go through points, find distance between them and join them
    for (int i = 0; i < vertices.size() - 1; i++) {
      Point curr = vertices.at(i);
      Point next = vertices.at(i + 1);
      result += curr.distance_to_point(next);
    }
    return result;
  }
};

class AUV {
private:
  std::string name;
  Point position;
  double depth;
  double heading;
  double speed[3] = {0, 0, 0};
  double angular_speed;
public:
  AUV(std::string name, Point position, double depth, double heading, double speed[3], double angular_speed) {
    this->name = name;
    this->position = position;
    this->depth = depth;
    this->heading = heading;
    this->speed[0] = speed[0];
    this->speed[1] = speed[1];
    this->speed[2] = speed[2];
    this->angular_speed = angular_speed;
  }

  void step(double dt) {
    /* 
      Takes a double parameter dt and moves the AUV using speed.
    */

    position.x += dt * speed[0];
    position.y += dt * speed[2];
    depth += dt * speed[1];
  }

  void apply_acceleration(double acceleration[3]) {
    /*
     Takes an array<double> of size 3 and accelerates the AUV by the given acceleration.
     acceleration[0] = forward acceleration
     acceleration[1] = lateral acceleration
     acceleration[2] = vertical acceleration
    */

    // Update speed with acceleration
    speed[0] += acceleration[0];
    speed[1] += acceleration[1];
    speed[2] += acceleration[2];
  }

  void apply_angular_acceleration(double angular_acceleration) {
    /* 
      Takes a double parameter angular_acceleration and accelerates the AUV by the given angular acceleration
    */
  }
};

int main()
{
  int x = 10;
  int y = 5;
  int z = 5;
  std::cout << "x + y + z: " << x + y + z << std::endl;
  int w = 2;
  std::cout << "x * y * z * w: " << x * y * z * w << std::endl; 
  int v = 1;
  std::cout << "x / y / v" << x / y / v << std::endl;

  // Functions
  int sum = add(x, y); // call the add function
  int difference = subtract(x, y);
  int product = multiply(x, y);
  int quotient = divide(x, y);
  std::cout << "The sum of " << x << " and " << y << " is " << sum << std::endl;
  std::cout << "The difference of " << x << " and " << y << " is " << difference << std::endl;
  std::cout << "The product of " << x << " and " << y << " is " << product << std::endl;
  std::cout << "The quotient of " << x << " and " << y << " is " << quotient << std::endl;

  // Classes
  Circle c(2);
  std::cout << "The area of a circle with radius " << c.radius << " is " << c.area() << std::endl;

  // Problem 1
  Point p(3, 4);
  std::cout << "The distance of point p from the origin is " << p.distance_to_origin() << std::endl;

  // Problem 2
  Point q(1, 2);
  std::cout << "The distance between point p and q is " << p.distance_to_point(q) << std::endl;

  // Problem 3
  Line l(p, q);
  std::cout << "The length of line l is " << l.length() << std::endl;

  // Problem 4
  Point r(-5, -5);
  std::cout << "The distance from line l to point r is " << l.distance_to_point(r) << std::endl;

  // Problem 6
  Triangle t(Point(1, 1), Point(2.5, 3), Point(5, 1));
  std::cout << "The area of triangle t is " << t.area() << std::endl;

  // Problem 7
  std::vector<Point> vertices {Point(1, 1, 1)};

  return 0;
}