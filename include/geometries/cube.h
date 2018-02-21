#ifndef __CUBE_H__
#define __CUBE_H__
#include<geometries/geometry.h>

class Cube : public Geometry {

private:
	Cube();
	glm::vec3 calculateVertexPositionForCube(const glm::vec3 center, const float radius, const int32_t X_SIDE, const int32_t Y_SIDE, const int32_t Z_SIDE);
	void createCube(const glm::vec3 center, const float radius);

public:
	Cube(const glm::vec3 center, const float geometryRadius);
	~Cube();
};

#endif