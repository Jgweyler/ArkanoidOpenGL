#include <gameObjects/platform.h>

Platform::Platform(Drawable &platformDrawable) {
	drawable = platformDrawable;
	platformSpeed = 0.5f;
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

}

void Platform::render(glm::mat4 projection, glm::mat4 view, glm::vec3 cameraPos, glm::vec3 lightPos) {
	drawable.render(projection, view, position, cameraPos, lightPos);
}