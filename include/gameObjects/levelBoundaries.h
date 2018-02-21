#ifndef __LEVELBOUNDARIES_H__
#define __LEVELBOUNDARIES_H__

#include <gameObjects\wall.h>

const float MAX_LEFT = -11.5f;
const float MAX_RIGHT = 11.5f;
const float MAX_TOP = 21.0f;
const glm::vec3 LEFT_WALL_POS = glm::vec3(MAX_LEFT, 0.0f, 0.0f);
const glm::vec3 RIGHT_WALL_POS = glm::vec3(MAX_RIGHT, 0.0f, 0.0f);
const glm::vec3 TOP_WALL_POS = glm::vec3(0.0f, MAX_TOP, 0.0f);

const glm::vec3 SIDE_WALLS_SCALE = glm::vec3(1.0f, 20.0f, 1.0f);
const glm::vec3 TOP_WALLS_SCALE = glm::vec3(22.0f, 1.0f, 1.0f);


class LevelBoundaries : public GameObject {


public:
	LevelBoundaries() {};
	LevelBoundaries(Wall* top, Wall* left, Wall* right);
	~LevelBoundaries();

	void update(const float dt);
	void render(glm::mat4 projection, glm::mat4 view, glm::vec3 cameraPos, glm::vec3 lightPos);
};
#endif