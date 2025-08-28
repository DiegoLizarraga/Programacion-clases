#include "Shape.h"

Shape::Shape(int X, int Y) {
    x = X;
    y = Y;
}

string Shape::draw() {
    return "soy una figura";
}

int Shape::getX() {
    return x;
}