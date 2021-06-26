#ifndef SHAPE_HPP
#define SHAPE_HPP

class Shape
{
public:
	virtual void area() const = 0;
	virtual void volume() const = 0;
};

#endif