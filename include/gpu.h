#ifndef __GUP_H__
#define __GPU_H__

#include <geometries\geometry.h>
#include <cstdint>

const uint32_t NUM_OF_GEOMETRIES = 2; // Cube and Sphere.

class GPU {

private:

	uint32_t VAOs[NUM_OF_GEOMETRIES];
	uint32_t VBOs[NUM_OF_GEOMETRIES];
	uint32_t EBOs[NUM_OF_GEOMETRIES];

	void uploadVertexDataToGPU(Geometry &geometry, uint32_t &VAO, uint32_t *VBO, uint32_t *EBO);

public:
	GPU();
	~GPU();
	void createVertexData(Geometry& geometry);
	void bindCubeVAO() const;
	void bindSphereVAO() const;
	void unbindVAO() const;
	//void activateTexture() const;
};

#endif