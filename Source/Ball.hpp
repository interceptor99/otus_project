#pragma once
#include "Painter.hpp"
#include "Point.hpp"
#include "Velocity.hpp"

class Ball {

    Color _color;
    Velocity _velocity;
    Point _center;
    double _radius;
    bool _isCollidable;

  public:

    Ball(double x, double y, double radius, const Color& color, bool isCollidable);

    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;
    void draw(Painter& painter) const;
    void setCenter(const Point& center);
    Point getCenter() const;
    double getRadius() const;
    double getMass() const;
    bool getIsCollidable() const;
};
