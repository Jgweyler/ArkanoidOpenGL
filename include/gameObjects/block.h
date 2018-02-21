#ifndef __BLOCK_H__
#define __BLOCK_H__

#include <gameObjects/brick.h>

const uint32_t MAX_BRICKS_PER_ROW = 10;
const uint32_t MAX_BRICKS_PER_COL = 10;

class Block : public GameObject {
private:
	uint32_t rows;
	uint32_t cols;

	Drawable* drawable_;
	Ball* ball_;
	Brick bricks [MAX_BRICKS_PER_ROW][MAX_BRICKS_PER_COL];

public:
	Block();
	Block(Drawable* drawable,Ball* ball, const uint32_t width, const uint32_t height, const uint32_t n_hits, const glm::vec3 pos);
	~Block();
	void initialize(Drawable* drawable, Ball* ball, const uint32_t width, const uint32_t height, const uint32_t n_hits, const glm::vec3 pos);
	void update(const float dt);
	void render(glm::mat4 projection, glm::mat4 view, glm::vec3 cameraPos, glm::vec3 lightPos);
};
#endif