#include <gameObjects\levelBoundaries.h>

LevelBoundaries::LevelBoundaries(Wall* top, Wall* left, Wall* right) {

	//left->setPosition(LEFT_WALL_POS);

	float geometryRadius = top->getGeometryRadius();
	float yPos = (geometryRadius * SIDE_WALLS_SCALE.y) + geometryRadius;

	left->setPosition(LEFT_WALL_POS + glm::vec3(0.0f, yPos, 0.0f));
	left->setScale(SIDE_WALLS_SCALE);

	
	right->setPosition(RIGHT_WALL_POS + glm::vec3(0.0f, yPos, 0.0f));
	right->setScale(SIDE_WALLS_SCALE);

	top ->setPosition(TOP_WALL_POS);
	top->setScale(TOP_WALLS_SCALE);

	addChild(top);
	addChild(left);
	addChild(right);
}

LevelBoundaries::~LevelBoundaries() {

}

void LevelBoundaries::update(const float dt) {
	if (dirtyFlag) {
		for (uint32_t i = 0; i < MAX_NUM_OF_CHILDREN; i++) {
			if (children[i] == NULL)
				break;
			else
				children[i]->update(dt);
		}
		dirtyFlag = false;
	}
}


void LevelBoundaries::render(glm::mat4 projection, glm::mat4 view, glm::vec3 cameraPos, glm::vec3 lightPos) {
	for (uint32_t i = 0; i < MAX_NUM_OF_CHILDREN; i++) {
		if (children[i] != NULL)
			children[i]->render(projection, view, cameraPos, lightPos);
		else
			break;
	}
}
