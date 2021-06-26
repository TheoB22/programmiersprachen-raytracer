#include "Sphere.hpp"

Sphere::Sphere(glm::vec3 const& center, float r, std::string const& name, Color const& color) :
	Shape{ name, color },
	center_{ center },
	radius_{ r } {};

float Sphere::area() const  {
	return (4 * M_PI * radius_ * radius_);
}

float Sphere::volume() const {
	return (M_PI * 4 / 3 * radius_ * radius_ * radius_);
}

Hitpoint Sphere::intersect(Ray& ray) const {
	float distance = 0.0f;
	bool intersected;
	intersected = glm::intersectRaySphere(ray.origin, ray.direction, center_, radius_, distance);
	return Hitpoint{ intersected, distance, name_, color_,
			ray.origin + ray.direction * distance, ray.direction };
}

std::ostream& Sphere::print(std::ostream& os) const {
	os << name_ << " Color: " << color_ << " center: x: " << center_.x << " y: " 
		<< center_.y << " z: " << center_.z << " Radius: " << radius_;
	return os;
}