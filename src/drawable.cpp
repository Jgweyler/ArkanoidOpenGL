#include <drawable.h>
#include <glad\glad.h>

#include<glm/gtc/matrix_transform.hpp>

Drawable::Drawable() {

}

Drawable::Drawable(Geometry * geometry, Material*  material) {
	geometry_ = geometry;
	material_ = material;
}

Drawable::~Drawable() {

}

float Drawable::getGeometryRadius() const {
	return geometry_->getRadius();
}

Material* Drawable::getMaterial() const {
	return material_;
}

void Drawable::render(glm::mat4 projection, glm::mat4 view, glm::mat4 model, glm::vec3 cameraPos, glm::vec3 lightPos) {

	material_->use();
	material_->set("projection", projection);
	material_->set("view", view);
	material_->set("model", model);

	glm::mat3 normalMat = glm::inverse(glm::transpose(glm::mat3(model)));
	material_->set("normalMat", normalMat);

	
	if (geometry_->getGeometryType() == Geometry::Type::Cube) {
		material_->set("viewPos", cameraPos);

		material_->set("material.diffuse", 0);
		material_->set("material.specular", 1);
		material_->set("material.shininess", 32.0f);

		material_->set("light.position", lightPos);
		material_->set("light.ambient", 0.2f, 0.15f, 0.1f);
		material_->set("light.diffuse", 0.5f, 0.5f, 0.5f);
		material_->set("light.specular", 1.0f, 1.0f, 1.0f);
		glActiveTexture(GL_TEXTURE0);
		material_->bindDiffTexture();

		glActiveTexture(GL_TEXTURE1);
		material_->bindSpecTexture();
		glBindVertexArray(1);
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	}
	else if (geometry_->getGeometryType() == Geometry::Type::Sphere) {
		glBindVertexArray(2);
		glDrawElements(GL_TRIANGLES, 540, GL_UNSIGNED_INT, 0);
	}
	glBindVertexArray(0);
}

