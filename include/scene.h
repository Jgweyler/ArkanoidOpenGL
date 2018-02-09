#ifndef __SCENE_H__
#define __SCENE_H__

#include <camera.h>
#include <gameObject.h>

#include <stdint.h>

const uint32_t num_of_gameObjects = 4;
const glm::vec3 CAMERA_POS = glm::vec3(0.0f, 10.0f, 30.0f);
const glm::vec3 LIGHT_POS = glm::vec3(1.2f, 1.0f, 3.0);

const uint32_t k_screen_width = 800;
const uint32_t k_screen_height = 800;

class Scene {
private:
	Camera camera_ = Camera(CAMERA_POS);
	glm::mat4 projection_;
	glm::mat4 view_;
	GameObject* gameObjects[num_of_gameObjects];

public:
	Scene();
	Scene(Camera& camera);
	~Scene();

	void addGameObject(GameObject* gameObject);
	void update(const float dt);
	void render();



};
#endif
