#ifndef __GEOMETRYFACTORY_H__
#define __GEOMETRYFACTORY_H__

#include <geometries\grid.h>
#include <geometries\cube.h>

class GeometryFactory {

public:
	enum class ShapeType {
		Grid = 0,
		Cube = 1,
	};

	static Geometry * createGeometry(const ShapeType geometryType, glm::vec3 center, float radius);
};
#endif