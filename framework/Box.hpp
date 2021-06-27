#ifndef BOX_HPP
#define BOX_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"


class Box : public Shape {
public:
	Box(glm::vec3 const&  min, glm::vec3 const& max, std::string const& name, Color const& color);

	float area() const override;

	float volume() const override;

	std::ostream& print(std::ostream& os) const override;

private:
	glm::vec3 min_;
	glm::vec3 max_;
	float a_;
	float b_;
	float c_;
};


#endif