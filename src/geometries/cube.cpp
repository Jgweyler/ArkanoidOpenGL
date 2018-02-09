#include <geometries/cube.h>

Cube::Cube(const glm::vec3 center, const float radius) {

	type = Geometry::Type::Cube;

	constexpr uint32_t faces = 6;
	constexpr uint32_t nVerts =  4 * faces; // 4 vertex per face (6).
	constexpr uint32_t nTexCoords = 2 * nVerts;

	vertexDataSize = nVerts * 3;
	normalsDataSize = 3 * nVerts;
	texCoordsDataSize = 2 * nVerts;
	elementsDataSize = 36; // 6 Faces, 2 triangles per face (6 verts) -> 6 * 6



	vertexData = new float[vertexDataSize];
	normalsData = new float[normalsDataSize];
	texCoordsData = new float[texCoordsDataSize];
	elementsData = new uint32_t[elementsDataSize];


	createCube(center, radius);
}

Cube::~Cube() {
	//Call parent Destructor (Geometry.cpp)
}

glm::vec3 Cube::calculateVertexPositionForCube(const glm::vec3 center, const float radius, const int32_t X_SIDE, const int32_t Y_SIDE, const int32_t Z_SIDE) {
	glm::vec3 pos;
	pos.x = center.x + (X_SIDE * radius);
	if (abs(pos.x) < 0.01) pos.x = 0;
	pos.y = center.y + (Y_SIDE * radius);
	if (abs(pos.y) < 0.01) pos.y = 0;
	pos.z = center.z + (Z_SIDE * radius);
	if (abs(pos.z) < 0.01) pos.z = 0;

	return pos;
}

//TODO: Implementar la forma procedural y estructurada de añadir atributos (Coordenadas de texturas, normales...)

void Cube::createCube(const glm::vec3 center, const float radius) {

	const uint32_t FRONT = 0;
	const uint32_t RIGHT = 1;
	const uint32_t BACK = 2;
	const uint32_t LEFT = 3;
	const uint32_t BOTTOM = 4;
	const uint32_t TOP = 5;

	const uint32_t nFaces = 6;
	const uint32_t nVertexPerFace = 4;

	uint32_t verticesArrayCounter = 0;
	uint32_t texCoordsArrayCounter = 0;
	uint32_t normalsArrayCounter = 0;

	const uint32_t NEGATIVE_AXIS = -1;
	const uint32_t POSITIVE_AXIS = 1;

	const glm::vec3 front_Normals(0.0f, 0.0f, 1.0f);
	const glm::vec3 right_Normals(1.0f, 0.0f, 0.0f);
	const glm::vec3 back_Normals(0.0f, 0.0f, -1.0f);
	const glm::vec3 left_Normals(-1.0f, 0.0f, 0.0f);
	const glm::vec3 bottom_Normals(0.0f, -1.0f, 0.0f);
	const glm::vec3 top_Normals(0.0f, 1.0f, 0.0f);



	glm::vec3 pos[nVertexPerFace];
	glm::vec2 uvCoords[nVertexPerFace];
	glm::vec3 normals;


	for (uint32_t i = 0; i < nFaces; i++) {
		switch (i) {
		case FRONT:
			pos[0] = calculateVertexPositionForCube(center, radius, NEGATIVE_AXIS, NEGATIVE_AXIS, POSITIVE_AXIS); uvCoords[0].x = 0.0f; uvCoords[0].y = 0.0f;
			pos[1] = calculateVertexPositionForCube(center, radius, POSITIVE_AXIS, NEGATIVE_AXIS, POSITIVE_AXIS);  uvCoords[1].x = 1.0f; uvCoords[1].y = 0.0f;
			pos[2] = calculateVertexPositionForCube(center, radius, POSITIVE_AXIS, POSITIVE_AXIS, POSITIVE_AXIS);   uvCoords[2].x = 1.0f; uvCoords[2].y = 1.0f;
			pos[3] = calculateVertexPositionForCube(center, radius, NEGATIVE_AXIS, POSITIVE_AXIS, POSITIVE_AXIS);  uvCoords[3].x = 0.0f; uvCoords[3].y = 1.0f;
			normals = front_Normals;
			break;
		case RIGHT:
			pos[0] = calculateVertexPositionForCube(center, radius, POSITIVE_AXIS, NEGATIVE_AXIS, POSITIVE_AXIS);  uvCoords[0].x = 0.0f; uvCoords[0].y = 0.0f;
			pos[1] = calculateVertexPositionForCube(center, radius, POSITIVE_AXIS, NEGATIVE_AXIS, NEGATIVE_AXIS); uvCoords[1].x = 1.0f; uvCoords[1].y = 0.0f;
			pos[2] = calculateVertexPositionForCube(center, radius, POSITIVE_AXIS, POSITIVE_AXIS, NEGATIVE_AXIS);  uvCoords[2].x = 1.0f; uvCoords[2].y = 1.0f;
			pos[3] = calculateVertexPositionForCube(center, radius, POSITIVE_AXIS, POSITIVE_AXIS, POSITIVE_AXIS);   uvCoords[3].x = 0.0f; uvCoords[3].y = 1.0f;
			normals = right_Normals;
			break;
		case BACK:
			pos[0] = calculateVertexPositionForCube(center, radius, NEGATIVE_AXIS, NEGATIVE_AXIS, NEGATIVE_AXIS); uvCoords[0].x = 1.0f; uvCoords[0].y = 0.0f;
			pos[1] = calculateVertexPositionForCube(center, radius, NEGATIVE_AXIS, POSITIVE_AXIS, NEGATIVE_AXIS);  uvCoords[1].x = 1.0f; uvCoords[1].y = 1.0f;
			pos[2] = calculateVertexPositionForCube(center, radius, POSITIVE_AXIS, POSITIVE_AXIS, NEGATIVE_AXIS);   uvCoords[2].x = 0.0f; uvCoords[2].y = 1.0f;
			pos[3] = calculateVertexPositionForCube(center, radius, POSITIVE_AXIS, NEGATIVE_AXIS, NEGATIVE_AXIS);  uvCoords[3].x = 0.0f; uvCoords[3].y = 0.0f;
			normals = back_Normals;
			break;
		case LEFT:
			pos[0] = calculateVertexPositionForCube(center, radius, NEGATIVE_AXIS, NEGATIVE_AXIS, POSITIVE_AXIS);  uvCoords[0].x = 1.0f; uvCoords[0].y = 0.0f;
			pos[1] = calculateVertexPositionForCube(center, radius, NEGATIVE_AXIS, POSITIVE_AXIS, POSITIVE_AXIS);   uvCoords[1].x = 1.0f; uvCoords[1].y = 1.0f;
			pos[2] = calculateVertexPositionForCube(center, radius, NEGATIVE_AXIS, POSITIVE_AXIS, NEGATIVE_AXIS);  uvCoords[2].x = 0.0f; uvCoords[2].y = 1.0f;
			pos[3] = calculateVertexPositionForCube(center, radius, NEGATIVE_AXIS, NEGATIVE_AXIS, NEGATIVE_AXIS); uvCoords[3].x = 0.0f; uvCoords[3].y = 0.0f;
			normals = left_Normals;
			break;
		case BOTTOM:
			pos[0] = calculateVertexPositionForCube(center, radius, NEGATIVE_AXIS, NEGATIVE_AXIS, POSITIVE_AXIS);  uvCoords[0].x = 0.0f; uvCoords[0].y = 1.0f;
			pos[1] = calculateVertexPositionForCube(center, radius, NEGATIVE_AXIS, NEGATIVE_AXIS, NEGATIVE_AXIS); uvCoords[1].x = 0.0f; uvCoords[1].y = 0.0f;
			pos[2] = calculateVertexPositionForCube(center, radius, POSITIVE_AXIS, NEGATIVE_AXIS, NEGATIVE_AXIS);  uvCoords[2].x = 1.0f; uvCoords[2].y = 0.0f;
			pos[3] = calculateVertexPositionForCube(center, radius, POSITIVE_AXIS, NEGATIVE_AXIS, POSITIVE_AXIS);   uvCoords[3].x = 1.0f; uvCoords[3].y = 1.0f;
			normals = bottom_Normals;
			break;
		case TOP:
			pos[0] = calculateVertexPositionForCube(center, radius, NEGATIVE_AXIS, POSITIVE_AXIS, POSITIVE_AXIS);   uvCoords[0].x = 0.0f; uvCoords[0].y = 0.0f;
			pos[1] = calculateVertexPositionForCube(center, radius, POSITIVE_AXIS, POSITIVE_AXIS, POSITIVE_AXIS);    uvCoords[1].x = 1.0f; uvCoords[1].y = 0.0f;
			pos[2] = calculateVertexPositionForCube(center, radius, POSITIVE_AXIS, POSITIVE_AXIS, NEGATIVE_AXIS);   uvCoords[2].x = 1.0f; uvCoords[2].y = 1.0f;
			pos[3] = calculateVertexPositionForCube(center, radius, NEGATIVE_AXIS, POSITIVE_AXIS, NEGATIVE_AXIS);  uvCoords[3].x = 0.0f; uvCoords[3].y = 1.0f;
			normals = top_Normals;
			break;
		}
		for (uint32_t j = 0; j < nVertexPerFace; j++) {
			//Vertices
			vertexData[verticesArrayCounter] = pos[j].x; verticesArrayCounter++;
			vertexData[verticesArrayCounter] = pos[j].y; verticesArrayCounter++;
			vertexData[verticesArrayCounter] = pos[j].z; verticesArrayCounter++;

			//texCoords
			texCoordsData[texCoordsArrayCounter] = uvCoords[j].x; texCoordsArrayCounter++;
			texCoordsData[texCoordsArrayCounter] = uvCoords[j].y; texCoordsArrayCounter++;

			//Normals
			normalsData[normalsArrayCounter] = normals.x; normalsArrayCounter++;
			normalsData[normalsArrayCounter] = normals.y; normalsArrayCounter++;
			normalsData[normalsArrayCounter] = normals.z; normalsArrayCounter++;

		}
	}

	uint32_t elementsCounter = 0;

	//Elements
	for (uint32_t i = 0; i < nFaces; i++) {
		for (uint32_t j = 0; j < nFaces; j++) {
			if (i == 0) {
				elementsData[elementsCounter] = j;
				if(j == 3)
					elementsData[elementsCounter] = 0;
				if( j >3)
					elementsData[elementsCounter] = j -2;
			}
			else {
				elementsData[elementsCounter] = elementsData[elementsCounter - 6] + 4;
			}
			elementsCounter++;
		}
	}

	/*const uint32_t  Cube_indices[INDICES_DATA_SIZE] = { 0, 1, 2,		0, 2, 3,
														4, 5, 6,		4, 6, 7,
														8, 9, 10,		8, 10, 11,
														12, 13, 14,		12, 14, 15,
														16, 17, 18,		16, 18, 19,
														20, 21, 22,		20, 22, 23 };*/

}