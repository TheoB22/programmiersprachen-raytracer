#ifndef HITPOINT_HPP
#define HITPOINT_HPP
#include <string>
#include <color.hpp>
#include <glm/vec3.hpp>

struct Hitpoint {
	bool intersected;
	float distance;
	std::string name;
	Color color;
	glm::vec3 intersect_point;
	glm::vec3 direction;
};
#endif