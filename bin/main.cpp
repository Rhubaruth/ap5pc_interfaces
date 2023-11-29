#include <iostream>
#include <cmath>

template<class T>
class VectorAddable {
public:
	virtual T operator+(const T &other) const = 0;
};

template<class T> 
class Scalarable {
public:
	virtual float scalar(T other) const = 0;
	// virtual float norm() const = 0;
};

template<class T>
class AbstractEVector: public VectorAddable<T>, Scalarable<T> {
public:
	float _x, _y;

	static float norm(const T& other) {
		return sqrt(other.scalar(other));
	}
	
};

class Vector: public AbstractEVector<Vector> {
public:
	Vector(float x, float y) {
		_x = x;
		_y = y;
	}
	
	Vector operator+(const Vector &other) const {
		return Vector(_x + other._x, _y + other._y);
	}

	float scalar(Vector other) const {
		return _x * other._x + _y * other._y;
	} 

	friend std::ostream &operator<<(std::ostream &os, const Vector &vec) {
		os << "(" << vec._x << ", " << vec._y << ")";
		return os;
	}
};

template<class T>
class Subtractable {
public:
	virtual T operator-(const T& other) const = 0;
};

template<class T> 
class PointAddable {
public:
	virtual T add(const AbstractEVector<Vector>& vec) const = 0;
};

template<class T>
class AbstractEPoint: public Subtractable<T>, PointAddable<T> {
public:
	float _x, _y;

	T operator-(const T& other) const override {
		return T(_x - other._x, _y - other._y);
	}

	T add(const AbstractEVector<Vector>& vec) const override {
		return T(_x + vec._x, _y + vec._y);
	}

};

class Point: public AbstractEPoint<Point> {
public:
	Point(float x, float y) {
		_x = x;
		_y = y;
	}

	float distance(const Point& other) {
		auto diff = other - *this; 
		return AbstractEVector<Vector>::norm(Vector(diff._x, diff._y));
	}

	friend std::ostream &operator<<(std::ostream &os, const Point &vec) {
		os << "(" << vec._x << ", " << vec._y << ")";
		return os;
	}

};


int main() {
	Vector vec = Vector(4, 3);

	std::cout << vec.norm(vec) << std::endl;

	Point point = Point(4, 5) - Point(2, 3);
	Point point2 = Point(2, 10);
	std::cout << point << std::endl;
	std::cout << point2.distance(point) << std::endl;

	std::cout << point.add(Vector(10, 0)) << std::endl;


	std::cout << "Konec programu" << std::endl;
	return 0;
}