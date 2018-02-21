#ifndef __LEVEL_H__
#define __LEVEL_H__

#include <gameObjects\levelBoundaries.h>
#include <gameObjects\block.h>

const uint32_t MAX_NUM_OF_BLOCKS_PER_LEVEL = 5;

class Level : public GameObject {
private:

	LevelBoundaries boundaries;
	uint32_t nBlocks;
	Block blocks[MAX_NUM_OF_BLOCKS_PER_LEVEL];

public:
	Level();
	Level(Drawable * cube_drawable, Ball* ball, const char * path);
	void update(const float dt);
	void render(glm::mat4 projection, glm::mat4 view, glm::vec3 cameraPos, glm::vec3 lightPos);

};
#endif // !__LEVEL_H__
