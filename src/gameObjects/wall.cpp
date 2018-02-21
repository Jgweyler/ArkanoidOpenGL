#include <gameObjects/wall.h>

#include<glm/gtc/matrix_transform.hpp>

Wall::Wall() {
	drawable_ = NULL;
}
Wall::Wall(Drawable * drawable, glm::vec3 pos) {
	drawable_ = drawable;
	position = pos;
}

void Wall::update(const float dt) {
	
}

void Wall::render(glm::mat4 projection, glm::mat4 view, glm::vec3 cameraPos, glm::vec3 lightPos) {
	model = glm::mat4(1.0f);
	model = glm::translate(model, position);
	model = glm::scale(model, scale);
	drawable_ ->render(projection, view, model, cameraPos, lightPos);
}

float Wall::getGeometryRadius() const {
	return drawable_->getGeometryRadius();
}