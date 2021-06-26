#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "box.hpp"
#include "shape.hpp"
#include "sphere.hpp"
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>


TEST_CASE("test volume and area of Sphere", "[vasphere]") {
	Sphere s1({ 0,0,0 }, 1.0f, "s1", { 0,0,0 });
	REQUIRE(s1.area() == Approx(12.5663706144));
	REQUIRE(s1.volume() == Approx(4.18879020479));
	Sphere s2({ 0,0,0 }, 0.0f, "s2", { 0,0,0 });
	REQUIRE(s2.area() == Approx(0.0f));
	REQUIRE(s2.volume() == Approx(0.0f));
}

TEST_CASE("test volume and area of Box", "[vabox]") {
	Box b1({ 0,0,0 }, { 2,4,6 }, "b1", { 0,0,0 });
	REQUIRE(b1.area() == Approx(88.0f));
	REQUIRE(b1.volume() == Approx(48.0f));
	Box b2({ 0,0,0 }, { 0,0,0 }, "b2", { 0,0,0 });
	REQUIRE(b2.area() == Approx(0.0f));
	REQUIRE(b2.volume() == Approx(0.0f));
}

TEST_CASE("test printign box and sphere") {
	Sphere s1({ 0,0,0 }, 1.0f, "s1", { 0,0,0 });
	std::cout << s1 << std::endl;
	Box b1({ 0,0,0 }, { 2,4,6 }, "b1", { 0,0,0 });
	std::cout << b1 << std::endl;
}

TEST_CASE("intersect_ray_sphere", "[intersect]") {
	//Ray
	glm::vec3 ray_origin{ 0.0f, 0.0f, 0.0f };
	// ray direction has to be normalized !
	// you can use :
	// v = glm :: normalize ( some_vector )
	glm::vec3 ray_direction{ 0.0f, 0.0f, 1.0f };

	// Sphere
	glm::vec3 sphere_center{ 0.0f, 0.0f, 5.0f };
	float sphere_radius{ 1.0f };
	float distance = 0.0f;
	auto result = glm::intersectRaySphere(
		ray_origin, ray_direction,
		sphere_center,
		sphere_radius * sphere_radius, // squared radius !!!
		distance);
	REQUIRE(distance == Approx(4.0f));

	Sphere s1({ 10,10,10 }, 1.0f, "s1", { 0,0,0 });
	Ray r1{ {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f} };
	Hitpoint h1 = s1.intersect(r1);
	REQUIRE(h1.intersected == true);
	Ray r2{ {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f} };
	Hitpoint h2 = s1.intersect(r2);
	REQUIRE(h2.intersected == false);

	Ray r3{ {10.0f, 10.0f, 10.0f}, {0.0f, 0.0f, 1.0f} };
	Hitpoint h3 = s1.intersect(r3);
	REQUIRE(h3.intersected == true);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}	
