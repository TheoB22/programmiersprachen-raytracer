#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"
# define M_PI 3.14159265358979323846

class Sphere : public Shape {
public:
	Sphere(glm::vec3 center, float r) :
		center_{ center },
		radius_{ r } {};

	float area() const override {
		return (4 * M_PI * radius_ * radius_);
	}

	float volume() const override {
		return (M_PI * 4 / 3 * radius_ * radius_ * radius_);
	}

private:
	glm::vec3 center_;
	float radius_;
};

#endif