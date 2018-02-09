#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include<glm/glm.hpp>

class GameObject {
protected:
	GameObject();
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;

public:
	virtual ~GameObject() {};
	virtual void update(const float dt) = 0;
	virtual void render(glm::mat4 projection, glm::mat4 view, glm::vec3 cameraPos, glm::vec3 lightPos) = 0;

};
#endif