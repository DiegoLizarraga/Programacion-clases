#include "Circle.h"

Circle::Circle(int X, int Y, int R) : Shape(X, Y) {
    r = R;
}

string Circle::draw() {
    return "soy un círculo";
}