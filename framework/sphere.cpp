#include "Sphere.hpp"

Sphere::Sphere(glm::vec3 const& center, float r, std::string const& name, Color const& color) :
	Shape{ name, color },
	center_{ center },
	radius_{ r } {
	std::cout << "Sphere constructor is called" << std::endl;
};

float Sphere::area() const  {
	return (4 * M_PI * radius_ * radius_);
}

float Sphere::volume() const {
	return (M_PI * 4 / 3 * radius_ * radius_ * radius_);
}

Hitpoint Sphere::intersect(Ray const& ray) const {
	float distance = 0.0f;
	bool intersected;
	float len = sqrt(pow(ray.direction.x, 2) + pow(ray.direction.y, 2) + pow(ray.direction.z, 2));
	glm::vec3 direction = glm::vec3{ ray.direction.x / len,  ray.direction.y / len,  ray.direction.z / len };
	intersected = glm::intersectRaySphere(ray.origin, direction, center_, radius_, distance);
	if (intersected) {
		return Hitpoint{ intersected, distance, name_, color_,
		ray.origin + ray.direction * distance, direction };
	} 
	return Hitpoint{ false };
}

Sphere::~Sphere() {
	std::cout << "Sphere destructor is called" << std::endl;
}

std::ostream& Sphere::print(std::ostream& os) const {
	Shape::print(os);
	os << " center: x: " << center_.x << " y: " 
		<< center_.y << " z: " << center_.z << " Radius: " << radius_;
	return os;
}