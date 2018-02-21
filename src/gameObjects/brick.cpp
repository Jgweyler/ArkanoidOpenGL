#include <gameObjects\brick.h>
#include<glm/gtc/matrix_transform.hpp>

Brick::Brick() {
	drawable_ = NULL;
	ball_ = NULL;
	scale = BRICK_SCALE;
	hits = 0;
}

Brick::Brick(Drawable * drawable, Ball* ball) {
	drawable_ = drawable;
	ball_ = ball;
	scale = BRICK_SCALE;
	hits = 1;
	enabled = true;
	position = glm::vec3(0.0f, 5.0f, 0.0f);

	float brickRadiusX = getGeometryRadius().x;
	float brickRadiusY = getGeometryRadius().y;

	collider_.initialize(position.x - brickRadiusX,
						 position.x + brickRadiusX,
						 position.y + brickRadiusY,
						 position.y - brickRadiusY);

}

void Brick::initialize(Drawable * drawable, Ball* ball, const uint32_t n_hits, const glm::vec3 pos) {
	drawable_ = drawable;
	ball_ = ball;
	hits = n_hits;
	scale = BRICK_SCALE;
	position = pos;
	enabled = true;

	float brickRadiusX = getGeometryRadius().x;
	float brickRadiusY = getGeometryRadius().y;

	collider_.initialize(position.x - brickRadiusX,
		position.x + brickRadiusX,
		position.y + brickRadiusY,
		position.y - brickRadiusY);

}

void Brick::update(const float dt) {
	if (!enabled || ball_->getCollideThisFrame()) return;

	if (collider_.checkCollision(ball_->getCollider())) {
		ball_->setCollideThisFrame(true);

		hits -= 1;
		if (hits == 0)
			enabled = false;

		checkCollisionSide();
	}
}

void Brick::render(glm::mat4 projection, glm::mat4 view, glm::vec3 cameraPos, glm::vec3 lightPos) {
	if (!enabled)
		return;
	model = glm::mat4(1.0f);
	model = glm::translate(model, position);
	model = glm::scale(model, scale);
	drawable_->render(projection, view, model, cameraPos, lightPos);
}
glm::vec3 Brick::getGeometryRadius() const {
	return scale * drawable_->getGeometryRadius();
}

void Brick::checkCollisionSide() {

	float brickTopCollider = collider_.getTopLimit();
	float brickBottomCollider = collider_.getBottomLimit();


	if (ball_->getVelocity().y < 0) { //If ball is going down
		if (ball_->getPosition().y >= brickTopCollider) {
			std::cout << "Colisiono por arriba" << std::endl;
			ball_->reverseDirectionY(); //Ball is colliding with the top of the brick
		}
		else {
			std::cout << "Colisiono por un lado" << std::endl;
			ball_->reverseDirectionX(); //Ball is colliding with a side  of the brick
		}
	}
	else { //Ball is going up
		if (ball_->getPosition().y <= brickBottomCollider) {
			std::cout << "Colisiono por debajo" << std::endl;
			ball_->reverseDirectionY(); //Ball is colliding with the Bottom of the brick
		}
		else {
			ball_->reverseDirectionX(); //Ball is colliding with a side  of the brick
			std::cout << "Colisiono por un lado" << std::endl;
		}
	}
	
}