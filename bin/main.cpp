#include <iostream>
#include <Vector.h>
#include <Point.h>

using namespace std;

int main() {

auto ev = Point(2,3);
ev = ev.add(Vector(1, 3));
auto subev = ev.subs(Point(1,3));

cout << ev << endl;
cout << subev << endl;

Point p1 = Point(1,2);
Point p2 = Point(3,4);

float dist = p1.distancePoint(p2);
cout << dist;


}
