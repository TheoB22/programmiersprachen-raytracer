#include "Box.hpp"

Box::Box(glm::vec3 const&  min, glm::vec3 const& max, std::string const& name, Color const& color) :
	min_{ min },
	max_{ max },
	a_{ max.x - min.x },
	b_{ max.y - min.y },
	c_{ max.z - min.z },
	Shape{ name, color } {}


float Box::area() const {
	return(2 * (a_ * b_ + a_ * c_ + b_ * c_));
}

float Box::volume() const {
	return(a_ * b_ * c_);
}

std::ostream& Box::print(std::ostream& os) const {
	Shape::print(os);
	os << " a: " << a_ << " b: " << b_ << " c: " << c_;
	return os;
}