#include <scene.h>

#include<glm/gtc/matrix_transform.hpp>

Scene::Scene() {
	projection_ = glm::mat4(1.0f);
	projection_ = glm::perspective(glm::radians(camera_.getFOV()), (float)k_screen_width / (float)k_screen_height, 0.1f, 100.0f);
	view_ = camera_.getViewMatrix();

	for (uint32_t i = 0; i < num_of_gameObjects; i++) {
		gameObjects[i] = NULL;
	}
}
Scene::Scene(Camera& camera) {

	camera_ = camera;
	projection_ = glm::mat4(1.0f);
	projection_ = glm::perspective(glm::radians(camera_.getFOV()), (float)k_screen_width / (float)k_screen_height, 0.1f, 100.0f);
	view_ = camera_.getViewMatrix();
	for (uint32_t i = 0; i < num_of_gameObjects; i++) {
		gameObjects[i] = NULL;
	}
}

Scene::~Scene() {
	for (uint32_t i = 0; i < num_of_gameObjects; i++) {
		gameObjects[i] = NULL;
	}
}

void Scene::addGameObject(GameObject * gameObject) {
	for (uint32_t i = 0; i < num_of_gameObjects; i++) {
		if (gameObjects[i] == NULL) {
			gameObjects[i] = gameObject;
			break;
		}
	}
}

void Scene::update(const float dt) {
	for (uint32_t i = 0; i < num_of_gameObjects; i++)
		if (gameObjects[i] != NULL) {
			gameObjects[i]->update(dt);
		}
}
void Scene::render() {

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (uint32_t i = 0; i < num_of_gameObjects; i++)
		if (gameObjects[i] != NULL) {
			gameObjects[i]->render(projection_, view_, CAMERA_POS, LIGHT_POS);
		}
}

