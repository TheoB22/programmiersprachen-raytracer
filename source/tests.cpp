#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "sphere.hpp"
#include "box.hpp"


TEST_CASE("test volume and area of Sphere", "[vasphere]") {
	Sphere s1({ 0,0,0 }, 1.0f);
	REQUIRE(s1.area() == Approx(12.5663706144));
	REQUIRE(s1.volume() == Approx(4.18879020479));
	Sphere s2({ 0,0,0 }, 0.0f);
	REQUIRE(s2.area() == Approx(0.0f));
	REQUIRE(s2.volume() == Approx(0.0f));
}

TEST_CASE("test volume and area of Box", "[vabox]") {
	Box b1({ 0,0,0 }, { 2,4,6 });
	REQUIRE(b1.area() == Approx(88.0f));
	REQUIRE(b1.volume() == Approx(48.0f));
	Box b2({ 0,0,0 }, { 0,0,0 });
	REQUIRE(b2.area() == Approx(0.0f));
	REQUIRE(b2.volume() == Approx(0.0f));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}	
