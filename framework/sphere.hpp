#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"
# define M_PI 3.14159265358979323846

class Sphere : public Shape {
public:
	Sphere(glm::vec3 const& center, float r, std::string const& name, Color const& color);

	float area() const override;

	float volume() const override;

	std::ostream& print(std::ostream& os) const override;

protected:
	glm::vec3 center_;
	float radius_;
};

#endif