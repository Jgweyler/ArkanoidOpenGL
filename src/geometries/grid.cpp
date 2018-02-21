#include <geometries\grid.h>

Grid::Grid(const glm::vec3 center, const float radius) {

	this->radius = radius;
	const uint32_t nVertex = 4;

	const uint32_t TOP_LEFT = 0;
	const uint32_t TOP_RIGHT = 1;
	const uint32_t BOTTOM_LEFT = 2;
	const uint32_t BOTTOM_RIGHT = 3;

	const uint32_t POSITIVE_AXIS = 1;
	const uint32_t NEGATIVE_AXIS = -1;


	vertexDataSize = nVertex * 3;
	texCoordsDataSize = nVertex * 2;
	normalsDataSize = nVertex * 3;
	elementsDataSize = 6;	//Two traingles -> 6 elements.

	vertexData = new float[vertexDataSize];
	normalsData = new float[normalsDataSize];
	texCoordsData = new float[texCoordsDataSize];
	elementsData = new uint32_t[elementsDataSize];

	//indicesData = Grid_indices;

	glm::vec3 pos[nVertex];
	glm::vec2 uvCoords[nVertex];
	glm::vec3 normal = glm::vec3(0.0f, 1.0f, 0.0f);

	float tiled_textures = radius / 0.5f;

	pos[0] = calculateVertexPositionForGrid(center, radius, NEGATIVE_AXIS, POSITIVE_AXIS);  uvCoords[0].x = tiled_textures; uvCoords[0].y = 0.0f;
	pos[1] = calculateVertexPositionForGrid(center, radius, NEGATIVE_AXIS, NEGATIVE_AXIS); uvCoords[1].x = tiled_textures; uvCoords[1].y = tiled_textures; 
	pos[2] = calculateVertexPositionForGrid(center, radius, POSITIVE_AXIS, NEGATIVE_AXIS);  uvCoords[2].x = 0.0f; uvCoords[2].y = tiled_textures; 
	pos[3] = calculateVertexPositionForGrid(center, radius, POSITIVE_AXIS, POSITIVE_AXIS);   uvCoords[3].x = 0.0f; uvCoords[3].y = 0.0f; 

	uint32_t vertexArrayCounter = 0;
	uint32_t texCoordArrayCounter = 0;
	uint32_t normalsArrayCounter = 0;

	for (uint32_t i = 0; i < nVertex; i++) {
		//Vertex
		vertexData[vertexArrayCounter] = pos[i].x; vertexArrayCounter++;
		vertexData[vertexArrayCounter] = pos[i].y; vertexArrayCounter++;
		vertexData[vertexArrayCounter] = pos[i].z; vertexArrayCounter++;

		//TextureCoords
		texCoordsData[texCoordArrayCounter] = uvCoords[i].x; texCoordArrayCounter++;
		texCoordsData[texCoordArrayCounter] = uvCoords[i].y; texCoordArrayCounter++;

		//Normals
		normalsData[normalsArrayCounter] = normal.x; normalsArrayCounter++;
		normalsData[normalsArrayCounter] = normal.y; normalsArrayCounter++;
		normalsData[normalsArrayCounter] = normal.z; normalsArrayCounter++;
	}

	//Elements
	uint32_t elementIndex = 0;
	for (uint32_t i = 0; i < 2; i++) {
		for (uint32_t j = 0; j < 3; j++) {
			if (i == 0) {
				elementsData[elementIndex] = j;
			}
			else if (i > 0) {
				if (j == 0) {
					elementsData[elementIndex] = 0;
				}
				else {
					elementsData[elementIndex] = j + 1;
				}
			}

			elementIndex++;
		}
	}

		/*const uint32_t  Grid_indices [INDICES_DATA_SIZE] = {
															0, 1, 2,
															0, 2, 3
														}; */
}

Grid::~Grid() {
	//Call parent destructor (Geometry.cpp)
}


glm::vec3 Grid::calculateVertexPositionForGrid(const glm::vec3 center, const float radius, const int32_t X_SIDE, const int32_t Y_SIDE) {
	glm::vec3 pos;
	pos.x = center.x + (X_SIDE * radius);
	if (abs(pos.x) < 0.01) pos.x = 0;
	pos.y = center.y + (Y_SIDE * radius);;
	if (abs(pos.y) < 0.01) pos.y = 0;
	pos.z = center.z;
	if (abs(pos.z) < 0.01) pos.z = 0;

	return pos;
}
