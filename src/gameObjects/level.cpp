#include <gameObjects\level.h>
#include <fstream>
#include <sstream>
#include <string>

Level::Level() {}

Level::Level( Drawable*  cube_drawable, Ball* ball, const char* path) {
	std::ifstream levelFile(path);

	if (levelFile.is_open()) {
		std::string line;
		std::getline(levelFile, line);

		nBlocks = std::stoi(line);

		uint32_t blockWidth, blockHeight, n_hits;
		glm::vec3 pos;

		for (uint32_t i = 0; i < nBlocks; i++) {

			levelFile >> blockWidth >> blockHeight >> n_hits;
			levelFile >> pos.x >> pos.y >> pos.z;

			blocks[i].initialize(cube_drawable, ball, blockWidth, blockHeight, n_hits, pos);

			addChild(&blocks[i]);
		}
		levelFile.close();
	} 

}

Block::~Block() {

}

void Level::update(const float dt) {
	for (uint32_t i = 0; i < MAX_NUM_OF_CHILDREN; i++) {
		if (children[i] == NULL)
			break;
		else
			children[i]->update(dt);
	}
}

void Level::render(glm::mat4 projection, glm::mat4 view, glm::vec3 cameraPos, glm::vec3 lightPos) {
	for (uint32_t i = 0; i < MAX_NUM_OF_CHILDREN; i++) {
		if (children[i] != NULL)
			children[i]->render(projection, view, cameraPos, lightPos);
		else
			break;
	}
}