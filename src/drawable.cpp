#include <drawable.h>
#include <glad\glad.h>

#include<glm/gtc/matrix_transform.hpp>

Drawable::Drawable() {

}

Drawable::Drawable(Geometry &geometry, Material &material) {
	geometry_ = geometry;
	material_ = material;
}

Drawable::~Drawable() {

}

void Drawable::render(glm::mat4 projection, glm::mat4 view, glm::vec3 position, glm::vec3 cameraPos, glm::vec3 lightPos) {

	glm::mat4 model = glm::mat4(1.0);
	model = glm::translate(model, position);
	material_.use();
	material_.set("projection", projection);
	material_.set("view", view);
	material_.set("model", model);

	glm::mat3 normalMat = glm::inverse(glm::transpose(glm::mat3(model)));
	material_.set("normalMat", normalMat);

	material_.set("viewPos", cameraPos);

	material_.set("material.diffuse", 0);
	material_.set("material.specular", 1);
	material_.set("material.shininess", 32.0f);

	material_.set("light.position", lightPos);
	material_.set("light.ambient", 0.2f, 0.15f, 0.1f);
	material_.set("light.diffuse", 0.5f, 0.5f, 0.5f);
	material_.set("light.specular", 1.0f, 1.0f, 1.0f);

	glActiveTexture(GL_TEXTURE0);
	material_.bindDiffTexture();

	glActiveTexture(GL_TEXTURE1);
	material_.bindSpecTexture();

	glBindVertexArray(1);

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
}

