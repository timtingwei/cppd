// "Copyright [2017] <Tim Hu>"
#include <iostream>
/*
  Organize the types into an inheritance hierarchy
  Geometric primitives(such as box, circle, sphere, cone)
 */

class Primitive {
 public:
  // Primitive() = default;
  Primitive(double, double);
  // virtual double get_area() {return x_size * y_size;}

  // virtual ~Primitive() = default;
 protected:
  double x_size = 0.0;
  double y_size = 0.0;
};

class Primitive_2d : public Primitive {
 public:
  // Primitive_2d() = default;
  Primitive_2d(double, double);
  virtual double area() = 0;           // pure virtual function
  virtual double pcrimeter() = 0;      // pure virtual funtions
  // double get_area() {return x_size * y_size;} override
};

class Primitive_3d : public Primitive {
 public:
  // Primitive_3d() = default;
  // Primitive_3d(double h) : height(h) { }
  Primitive_3d(double, double, double);
  virtual double cubage() = 0;
  // virtual double get_volumn() { return get_area()*height;}
  // ~virtual Primitive_3d() = default;
  // protected:
  // double height;
};

class Rectangle : public Primitive_2d {
 public:
  // Rectangle() = default;
  // Rectangle(double x, double y) : x_size(x), y_size(y) {}
  Rectangle(double, double);
  double area() override {return x_size * y_size;}
  double pcrimeter() override {return 2 * (x_size + y_size);}
  // double get_area() { return x_size * y_size;} override
};

class Circle : public Primitive_2d {
 public:
  // Circle() = default;
  // Circle(double &r) : radius(r) {}
  Circle(double, double);
  double area() override {return 3.14 * radius * radius;}
  double pcrimeter() override {return 2 * 3.14 * radius;}
  // double get_area() {  return (3.14 * radius * radius);} override
 protected:
  double radius = 0.0;
};

class Box : public Primitive_3d {
 public:
  // Box() = default;
  // Box(double x, doubly y, double h):
  // Primitive_3d(h), x_size(x), y_size(y) {}
  Box(double, double, double);
  double cubage() override {
    return height* x_size* y_size;
  }
 protected:
  double height = 0.0;
  double x_size = 0.0;
  double y_size = 0.0;
};

class Cone : public Primitive_3d {
 public:
  // Cone() = default;
  // Cone(const double &r, const double &h, const double &temp) :
  // radius(r), height(h) {}
  // Cone(double r, double h, double s):radius(r), height(h) {}
  Cone(double r, double h, double s);
  double cubage() override {return 3.14 * radius * radius * height;}
  // double get_volumn() {return (3.14*radius*radius*height);} override
 protected:
  double radius = 0.0;
  double height = 0.0;
};

int main() {
  // Cone c {3.0, 2.0, 1.0};
  return 0;
}

