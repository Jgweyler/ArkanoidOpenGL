#ifndef __BALL_H__
#define __BALL_H__

#include <gameObject.h>
#include <drawable.h>
#include <gameObjects\platform.h>
#include <components\collider2d.h>

const glm::vec3 BALL_INITIAL_POS = glm::vec3(0.0f, 0.60f, 0.0f);
const float BALL_SCALE_FACTOR = 0.15f;
const float BALL_SPEED = 10.0f;

class Ball : public GameObject {
private:
	Drawable * drawable_;
	Platform* platform_;
	Collider2D collider_;

	glm::vec3 velocity_;
	float speed_;
	bool isMoving;
	bool collideThisFrame;

public:
	Ball();
	Ball(Drawable * drawable, Platform* player);
	void update(const float dt);
	void render(glm::mat4 projection, glm::mat4 view, glm::vec3 cameraPos, glm::vec3 lightPos);
	float getGeometryRadius() const;

	Collider2D& getCollider();

	void checkCollisions();
	glm::vec3 getVelocity();
	void reverseDirectionX();
	void reverseDirectionY();

	void startBall();
	void setCollideThisFrame(const bool collides);
	bool getCollideThisFrame();
};
#endif