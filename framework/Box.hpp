#ifndef BOX_HPP
#define BOX_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"


class Box : public Shape {
public:
	Box(glm::vec3 min, glm::vec3 max) :
		min_{ min },
		max_{ max },
		a_{ max.x - min.x },
		b_{ max.y - min.y },
		c_{ max.z - min.z } {}

	float area() const override {
		return(2* (a_*b_ + a_*c_ + b_*c_));
	}

	float volume() const override {
		return(a_ * b_ * c_);
	}

private:
	glm::vec3 min_;
	glm::vec3 max_;
	float a_;
	float b_;
	float c_;
};


#endif