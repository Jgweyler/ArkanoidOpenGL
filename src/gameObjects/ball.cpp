#include <gameObjects\ball.h>
#include<glm/gtc/matrix_transform.hpp>

Ball::Ball() {
	drawable_ = NULL;
	platform_ = NULL;
	velocity_ = glm::vec3(1.0f, 1.0f, 0.0f);
	speed_ = BALL_SPEED;
	position = BALL_INITIAL_POS;
	isMoving = false;
	collideThisFrame = false;
}
Ball::Ball(Drawable * drawable, Platform* player) {
	drawable_ = drawable;
	platform_ = player;
	velocity_ = glm::vec3(1.0f, 1.0f, 0.0f);
	position = BALL_INITIAL_POS;
	collider_.initialize(position.x - getGeometryRadius(),
						 position.x + getGeometryRadius(),
						 position.y + getGeometryRadius(),
						 position.y - getGeometryRadius());
	speed_ = BALL_SPEED;
	isMoving = false;
	collideThisFrame = false;

}
void Ball::update(const float dt) {
	float final_speed = speed_ * dt;
	if (isMoving) {
		checkCollisions();
		position += velocity_ * final_speed;
	}
	else {
		position = glm::vec3(platform_->getPosition().x, BALL_INITIAL_POS.y, 0.0f);
	}

	collider_.updateBoundaries(position.x - getGeometryRadius(),
							   position.x + getGeometryRadius(),
							   position.y + getGeometryRadius(),
							   position.y - getGeometryRadius());

	if (position.y < platform_->getPosition().y) {
		isMoving = false;
		position = BALL_INITIAL_POS;
		velocity_ = glm::vec3(1.0f, 1.0f, 0.0f);
	}
}
void Ball::render(glm::mat4 projection, glm::mat4 view, glm::vec3 cameraPos, glm::vec3 lightPos) {
	model = glm::mat4(1.0f);
	model = glm::translate(model, position);
	model = glm::scale(model, glm::vec3(BALL_SCALE_FACTOR, BALL_SCALE_FACTOR, BALL_SCALE_FACTOR));
	drawable_->render(projection, view, model, cameraPos, lightPos);
}
float Ball::getGeometryRadius() const {
	return drawable_->getGeometryRadius() *  BALL_SCALE_FACTOR;
}

void Ball::checkCollisions() {
	float  sphereColliderX = position.x + drawable_->getGeometryRadius();
	float  sphereColliderY = position.y + drawable_->getGeometryRadius();


	if (sphereColliderX > 11.5f ){
		velocity_.x *= -1.0f;
	}

	if (sphereColliderX < -10.0f){
		velocity_.x *= -1.0f;
	}

	if (sphereColliderY > 21.5f) {
		velocity_.y *= -1.0f;
	}

	if (collider_.checkCollision(platform_->getCollider())) {
		//If the ball is going up. Exit.
		if ((velocity_.y > 0.0f))
			return;

		float distance = abs(platform_->getPosition().x - position.x);
		float final_velocityY = 1.0f - (distance / platform_->getGeometryRadius().x);

		if (final_velocityY < 0.2) {
			velocity_.y = 0.2;
		}else
			velocity_.y = final_velocityY;

	}
}

Collider2D& Ball::getCollider() {
	return collider_;
}

glm::vec3 Ball::getVelocity() {
	return velocity_;
}

void Ball::reverseDirectionX() {
	velocity_.x *= -1.0;
}
void Ball::reverseDirectionY() {
	velocity_.y *= -1.0;
}

void Ball::startBall() {
	if(!isMoving)
		isMoving = true;
}

void Ball::setCollideThisFrame(const bool collides) {
	collideThisFrame = collides;
}

bool Ball::getCollideThisFrame() {
	return collideThisFrame;
}