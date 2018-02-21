#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__


#include <glm/glm.hpp>
#include <cstdint>
#include <iostream>

class Geometry {
public:

	enum class Type {
		Unknown = 0,
		Cube = 1,
		Sphere = 2,
	};

	Geometry();
	Geometry& operator=(const Geometry& other);
    ~Geometry();

	//Radius of the geometry.
	float radius; 

	float * getVertexData();
	float * getTexCoordData();
	float * getNormalsData();
	uint32_t * getElementsData();

	uint32_t getVertexDataSize();
	uint32_t getElementsDataSize();

	float * getBufferData();
	uint32_t getBufferDataSize();

	float getRadius() const;

	Geometry::Type getGeometryType() const;


protected:

	Geometry::Type type;
	uint32_t vertexDataSize;
	uint32_t normalsDataSize;
	uint32_t texCoordsDataSize;
	uint32_t elementsDataSize;
	float * vertexData;
	float * normalsData;
	float * texCoordsData;

	uint32_t * elementsData;
};

#endif