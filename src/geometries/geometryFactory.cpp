#include <geometries/geometryFactory.h>

Geometry* GeometryFactory::createGeometry(const ShapeType geometryType, glm::vec3 center, float radius) {

	switch (geometryType) {
	case ShapeType::Grid: return new Grid(center, radius); break;
	case ShapeType::Cube: return new Cube(center, radius); break;
	default: std::cout << "Error creating geometry. ShapeType does not exists." << std::endl; return NULL; break;
	}
}