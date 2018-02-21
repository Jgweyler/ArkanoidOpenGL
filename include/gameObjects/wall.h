#ifndef __WALL_H__
#define __WALL_H__

#include <gameObject.h>
#include <drawable.h>

class Wall : public GameObject {
private:
	Drawable * drawable_;
	

public:
	Wall();
	Wall(Drawable * drawable, glm::vec3 pos);
	void update(const float dt);
	void render(glm::mat4 projection, glm::mat4 view, glm::vec3 cameraPos, glm::vec3 lightPos);
	float getGeometryRadius() const;
};
#endif // !__WALL_H__