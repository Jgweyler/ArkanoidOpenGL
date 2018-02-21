#include <gameObject.h>

#include<glm/gtc/matrix_transform.hpp>

#include <iostream>

GameObject::GameObject() {

	position = glm::vec3(0.0f, 0.0f, 0.0f);
	rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	scale = glm::vec3(1.0f, 1.0f, 1.0f);
	model = glm::mat4(1.0f);
	model = glm::translate(model, position);
	model = glm::scale(model, scale);

	isParent = false;

	for (uint32_t i = 0; i < MAX_NUM_OF_CHILDREN; i++) {
		children[i] = NULL;
	}
}

void GameObject::update(const float dt) {
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

void GameObject::setPosition(const glm::vec3 newPosition) {
	position = newPosition;
}

void GameObject::setScale(const glm::vec3 newScale) {
	scale = newScale;
}

bool GameObject::isGameObjectParent() const {
	return isParent;
}

void GameObject::addChild(GameObject* child) {
	//If this gameObject is not parent yet, then set it as parent.
	if (!isParent)
		isParent = true;

	//Check if children array is full
	if (children[MAX_NUM_OF_CHILDREN - 1] != NULL) {
		std::cout << "Could not add child to gameObject. Children array is full." << std::endl;
		return;
	}

	for (uint32_t i = 0; i < MAX_NUM_OF_CHILDREN; i++) {
		if (children[i] == NULL) {
			children[i] = child;
			break;
		}
	}
}

glm::vec3 GameObject::getPosition() {
	return position;
}
