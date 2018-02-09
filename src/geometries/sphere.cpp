#include <geometries\sphere.h>

Sphere::Sphere (const float radius) {

	type = Geometry::Type::Sphere;

	constexpr uint32_t slices = 10;
	constexpr uint32_t stacks = 10;

	constexpr uint32_t nVerts = (slices + 1) * (stacks + 1);
	constexpr uint32_t elements = (slices * 2 * (stacks - 1)) * 3;

	vertexDataSize = 3 * nVerts;
	normalsDataSize = 3 * nVerts;
	texCoordsDataSize = 2 * nVerts;
	elementsDataSize = elements;

	vertexData = new float[vertexDataSize];			// Verts
	normalsData = new float[normalsDataSize];		// Normals
	texCoordsData = new float[texCoordsDataSize];	// Tex Coords
	elementsData = new uint32_t[elementsDataSize];	// Elements

	generateVerts(slices, stacks, radius);
}

Sphere::~Sphere() {
	//Call geometry Destructor
}

void Sphere::generateVerts(const uint32_t slices, const uint32_t stacks, const uint32_t radius) {
	float theta, phi;       // Generate positions and normals
	float thetaFac = (float)((2.0 * M_PI) / slices);
	float phiFac = (float)(M_PI / stacks);
	float nx, ny, nz, s, t;
	uint32_t idx = 0, tIdx = 0;
	for (uint8_t i = 0; i <= slices; i++) {
		theta = i * thetaFac;
		s = (float)i / slices;
		for (uint8_t j = 0; j <= stacks; j++) {
			phi = j * phiFac;
			t = (float)j / stacks;
			nx = sinf(phi) * cosf(theta);
			ny = sinf(phi) * sinf(theta);
			nz = cosf(phi);
			vertexData[idx] = radius * nx;
			vertexData[idx + 1] = radius * ny;
			vertexData[idx + 2] = radius * nz;
			normalsData[idx] = nx;
			normalsData[idx + 1] = ny;
			normalsData[idx + 2] = nz;
			idx += 3;

			texCoordsData[tIdx] = s;
			texCoordsData[tIdx + 1] = t;
			tIdx += 2;
		}
	}

	idx = 0;                      // Generate the element list
	for (uint8_t i = 0; i < slices; i++) {
		uint32_t stackStart = i * (stacks + 1);
		uint32_t nextStackStart = (i + 1) * (stacks + 1);
		for (uint8_t j = 0; j < stacks; j++) {
			if (j == 0) {
				elementsData[idx] = stackStart;
				elementsData[idx + 1] = stackStart + 1;
				elementsData[idx + 2] = nextStackStart + 1;
				idx += 3;
			}
			else if (j == stacks - 1) {
				elementsData[idx] = stackStart + j;
				elementsData[idx + 1] = stackStart + j + 1;
				elementsData[idx + 2] = nextStackStart + j;
				idx += 3;
			}
			else {
				elementsData[idx] = stackStart + j;
				elementsData[idx + 1] = stackStart + j + 1;
				elementsData[idx + 2] = nextStackStart + j + 1;
				elementsData[idx + 3] = nextStackStart + j;
				elementsData[idx + 4] = stackStart + j;
				elementsData[idx + 5] = nextStackStart + j + 1;
				idx += 6;
			}
		}
	}
}