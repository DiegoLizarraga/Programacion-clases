#include <iostream>
#include <string>

using namespace std;

class Shape {
protected:
    int x;
    int y;
  
public:
    Shape(int, int);
    virtual string draw();
    int getX();
};