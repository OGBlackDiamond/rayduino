#ifndef SHAPE_H
#define SHAPE_H

#include "color.h"
#include "vector.h"
#include "ray.h"

// this is an abstract class that all other shapes will inherit from
class Shape {
public:

    Shape();
    Shape(float, float, float, int, int, int);
    Shape(Vector3&, Color&);
    Shape(const Shape&);
    ~Shape();

    void setColor(Color);
    void setPosition(Vector3);

    Color& getColor();
    Vector3& getPosition();
    
    // each shape should override this
    bool checkCollision(Ray*);

protected:

    Vector3 position;
    Color color;

    void deepCopy(float, float, float, int, int, int);

};

#endif 
