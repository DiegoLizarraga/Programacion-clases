#include "Shape.h"

class Circle : public Shape {
private:
    int r;
public:
    Circle(int, int, int);
    string draw() override;
};