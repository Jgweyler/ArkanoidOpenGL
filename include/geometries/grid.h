#ifndef __GRID_H__
#define __GRID_H__

#include <geometries\geometry.h>



class Grid : public Geometry {

private:

	glm::vec3 calculateVertexPositionForGrid(const glm::vec3 center, const float radius, const int32_t X_SIDE, const int32_t Y_SIDE);
	Grid();

public:

	Grid(const glm::vec3 center, const float radius);
	~Grid();
};
#endif