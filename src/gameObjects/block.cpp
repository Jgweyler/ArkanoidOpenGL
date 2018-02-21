#include <gameObjects\block.h>

Block::Block() {
	drawable_ = NULL;
	ball_ = NULL;
	rows = 0;
	cols = 0;
}

Block::Block(Drawable* drawable, Ball* ball, const uint32_t width, const uint32_t height, const uint32_t n_hits, const glm::vec3 pos) {
	initialize(drawable, ball, width, height, n_hits, pos);
}

void Block::initialize(Drawable* drawable, Ball* ball, const uint32_t width, const uint32_t height, const uint32_t n_hits, const glm::vec3 pos) {
	
	drawable_ = drawable;
	ball_ = ball;
	cols = width;
	rows = height;
	position = pos;

	float posY = position.y;
	float posX = position.x;

	for (uint32_t i = 0; i < rows; i++) {
		for (uint32_t j = 0; j < cols; j++) {

			bricks[i][j].initialize(drawable_, ball_, n_hits, glm::vec3(posX, posY, 0.0f));

			posX += bricks[i][j].getGeometryRadius().x * 2.0f;

			if ((j + 1) % cols == 0) {
				posX = position.x;
			}

			if ((j + 1) % cols == 0) {
				posY -= (bricks[i][j].getGeometryRadius().y) * 2.0f;
			}

			addChild(&bricks[i][j]);
		}
	}
}

void Block::update(const float dt) {
		for (uint32_t i = 0; i < MAX_NUM_OF_CHILDREN; i++) {
			if (children[i] == NULL)
				break;
			else
				children[i]->update(dt);
		}
}


void Block::render(glm::mat4 projection, glm::mat4 view, glm::vec3 cameraPos, glm::vec3 lightPos) {
	for (uint32_t i = 0; i < MAX_NUM_OF_CHILDREN; i++) {
		if (children[i] == NULL)
			break;
		else
			children[i]->render(projection, view, cameraPos, lightPos);
	}
}