#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include<glm/glm.hpp>

const uint32_t MAX_NUM_OF_CHILDREN = 100;

class GameObject {
protected:
	GameObject();
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;

	glm::mat4 model;

	bool isParent;
	GameObject* children[MAX_NUM_OF_CHILDREN];

	//Checks if the children of this gameObject need to update their positions.
	bool dirtyFlag;

public:
	virtual ~GameObject() {};
	virtual void update(const float dt) = 0;
	virtual void render(glm::mat4 projection, glm::mat4 view, glm::vec3 cameraPos, glm::vec3 lightPos) = 0;
	void setPosition(const glm::vec3 newPosition);
	void setScale(const glm::vec3 newScale);

	glm::vec3 getPosition();

	//Checks if this game object is parent
	bool isGameObjectParent() const;
	//Add child to this gameObject
	void addChild(GameObject* child);

};
#endif