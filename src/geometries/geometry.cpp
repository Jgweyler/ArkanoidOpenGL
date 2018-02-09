#include <geometries\geometry.h>

Geometry::Geometry() {

	type = Geometry::Type::Unknown;
	vertexDataSize = 0;
	normalsDataSize = 0;
	texCoordsDataSize = 0;
	elementsDataSize = 0;
	vertexData = NULL;
	normalsData = NULL;
	texCoordsData = NULL;
	elementsData = NULL;
}

Geometry& Geometry::operator=(const Geometry& other) {
	return * this;
}

Geometry::~Geometry() {
	if (vertexData != NULL) {
		delete[] vertexData;
	}
	if (normalsData != NULL) {
		delete[] normalsData;
	}
	if (texCoordsData != NULL) {
		delete[] texCoordsData;
	}
	if (elementsData != NULL) {
		delete[] elementsData;
	}
}

float * Geometry::getVertexData() {
	return vertexData;
}

float * Geometry::getTexCoordData() {
	return texCoordsData;
}
float * Geometry::getNormalsData() {
	return normalsData;
}

uint32_t * Geometry::getElementsData() {
	return elementsData;
}

uint32_t Geometry::getVertexDataSize() {
	return vertexDataSize;
}

uint32_t Geometry::getElementsDataSize() {
	return elementsDataSize;
}

float * Geometry::getBufferData() {

	constexpr uint32_t maxBufferSize = 1000;

	float bufferData[maxBufferSize];

	uint32_t bufferIndex = 0;
	uint32_t texCoordIndx = 0;
	uint32_t normalsIndx = 0;

	for (uint32_t i = 0; i < vertexDataSize; i++) {
		bufferData[bufferIndex] = vertexData[i]; bufferIndex++;
		if ((i + 1) % 3 == 0) { //Once we insert three coords of one vertex
			//Add texCoords and normals of that vertex
			bufferData[bufferIndex] = texCoordsData[texCoordIndx]; bufferIndex++; texCoordIndx++;
			bufferData[bufferIndex] = texCoordsData[texCoordIndx]; bufferIndex++; texCoordIndx++;

			bufferData[bufferIndex] = normalsData[normalsIndx]; bufferIndex++; normalsIndx++;
			bufferData[bufferIndex] = normalsData[normalsIndx]; bufferIndex++; normalsIndx++;
			bufferData[bufferIndex] = normalsData[normalsIndx]; bufferIndex++; normalsIndx++;
		}
	}
	

	return bufferData;
}

uint32_t Geometry::getBufferDataSize() {
	return vertexDataSize + texCoordsDataSize + normalsDataSize;
}

Geometry::Type Geometry::getGeometryType() const {
	return type;
}

