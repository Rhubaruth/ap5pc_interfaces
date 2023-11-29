#include <AbstractEuclideanPoint.h>
#include <iostream>
#include <cmath>
class Point : public AbstractEuclideanPoint<Point> {

public:
    float x, y;

    Point(float x, float y) : x(x), y(y) {}

    Point add(const Vector &other) const override {
        return Point(x + other._x, y + other._y);
    }

    Point subs(const Point &other) const override {
        return Point(x - other.x, y - other.y);
    }

    //tuhle funkci jaksi potrebuju, protoze pokud chci distanci mezi Pointy... nemam tuhle funkci... a ja ji vynucuji a dedim z VectorScalarable
    float scalar(const Point& other) const {
        return x * other.x + y * other.y; 
    }


    friend std::ostream &operator<<(std::ostream &os, const Point &other)
    {
        os << other.x << " " << other.y;
        return os;
    }

 

};
