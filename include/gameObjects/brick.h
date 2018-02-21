#ifndef __BRICK_H__
#define __BRICK_H__

#include <gameObject.h>
#include <drawable.h>
#include <gameObjects\ball.h>
#include <components\collider2d.h>

const glm::vec3 BRICK_SCALE = glm::vec3(1.0f, 0.5f, 1.0f);

class Brick : public GameObject {
private:
	Drawable*  drawable_;
	Ball * ball_;
	Collider2D collider_;
	uint32_t hits;

	bool enabled;

	void checkCollisionSide();
public:
	Brick();
	Brick(Drawable * drawable, Ball* ball);
	void initialize(Drawable * drawable, Ball* ball, const uint32_t n_hits, const glm::vec3 pos );
	void update(const float dt);
	void render(glm::mat4 projection, glm::mat4 view, glm::vec3 cameraPos, glm::vec3 lightPos);
	glm::vec3 getGeometryRadius() const;
	
};
#endif