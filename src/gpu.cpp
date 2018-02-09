#include <gpu.h>
#include <glad\glad.h>

GPU::GPU() {
	for (uint32_t i = 0; i < NUM_OF_GEOMETRIES; i++) {
		VAOs[i] = 0;
		VBOs[i] = 0;
		EBOs[i] = 0;
	}
}

GPU::~GPU() {
	for (uint32_t i = 0; i < NUM_OF_GEOMETRIES; i++) {
		if (VAOs[i] != 0) {
			glDeleteVertexArrays(1, &VAOs[i]);
			glDeleteBuffers(1, &VBOs[i]);
			glDeleteBuffers(1, &EBOs[i]);
		}
	}
}

void GPU::uploadVertexDataToGPU(Geometry &geometry, uint32_t &VAO, uint32_t *VBO, uint32_t *EBO ) {


	uint32_t bufferDataSize = geometry.getBufferDataSize();
	uint32_t bufferElementsSize = geometry.getElementsDataSize();

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, VBO);

	glGenBuffers(1, EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, *VBO);
	glBufferData(GL_ARRAY_BUFFER, bufferDataSize * sizeof(float), geometry.getBufferData(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, bufferElementsSize * sizeof(uint32_t), geometry.getElementsData(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);


	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}

void GPU::createVertexData(Geometry &geometry) {
	Geometry::Type type = geometry.getGeometryType();

	switch (type) {
	case Geometry::Type::Cube:
		if (VAOs[0] == 0) {
			uploadVertexDataToGPU(geometry, VAOs[0], &VBOs[0], &EBOs[0]);
		}
		else {
			std::cout << "Cube buffer data alredy uploaded to GPU." << std::endl;
		}
		break;
	case Geometry::Type::Sphere:
		if (VAOs[1] == 0) {
			uploadVertexDataToGPU(geometry, VAOs[1], &VBOs[1], &EBOs[1]);
		}
		else {
			std::cout << "Sphere buffer data alredy uploaded to GPU." << std::endl;
		}
		break;
	default:
		std::cout << "Failed to upload geometry. This geometry is not recognized." << std::endl;
		break;
	}
}

void GPU::bindCubeVAO() const {
	glBindVertexArray(VAOs[0]);
}

void GPU::bindSphereVAO() const {
	glBindVertexArray(VAOs[1]);
}

void GPU::unbindVAO() const {
	glBindVertexArray(0);
}


