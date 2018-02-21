#include <gameObjects/platform.h>

#include<glm/gtc/matrix_transform.hpp>

Platform::Platform(Drawable &platformDrawable) {
	drawable = platformDrawable;
	platformSpeed = 0.5f;
	scale = glm::vec3(2.0f, 0.5f, 0.0f);

	float platformRadiusX = getGeometryRadius().x;
	float platformRadiusY = getGeometryRadius().y;

	collider_.initialize(position.x - platformRadiusX,
		position.x + platformRadiusX,
		position.y + platformRadiusY,
		position.y - platformRadiusY);
	
}

void Platform::handleKeyboard(const Movement direction, const float dt) {
	float velocity = platform_speed * dt;
	glm::vec3 right(1.0f, 0.0f, 0.0f);

	switch (direction) {
	case Movement::Left:
		position -= right * velocity; break;
	case Movement::Right:
		position += right * velocity; break;
	default: break;
	}

}

void Platform::update(const float dt) {
	model = glm::mat4(1.0f);
	model = glm::translate(model, position);
	model = glm::scale(model, scale);

	collider_.updateBoundaries(position.x - getGeometryRadius().x,
		position.x + getGeometryRadius().x,
		position.y + getGeometryRadius().y,
		position.y - getGeometryRadius().y);
}

void Platform::render(glm::mat4 projection, glm::mat4 view, glm::vec3 cameraPos, glm::vec3 lightPos) {
	drawable.render(projection, view, model, cameraPos, lightPos);
}

float Platform::getColliderRadiusX() {
	return drawable.getGeometryRadius() * scale.x;
}

float Platform::getColliderRadiusY() {
	return drawable.getGeometryRadius() * scale.y;
}

glm::vec3 Platform::getGeometryRadius() {
	return scale * drawable.getGeometryRadius();
}

Collider2D& Platform:: getCollider() {
	return collider_;
}