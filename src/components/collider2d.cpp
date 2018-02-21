#include <components\collider2d.h>
#include <iostream>

Collider2D::Collider2D() {
	limitX_1 = 0;
	limitX_2 = 0;

	limitY_1 = 0;
	limitY_2 = 0;
}

Collider2D::Collider2D(const float x_1, const float x_2, const float y_1, const float y_2) {
	limitX_1 = x_1;
	limitY_1 = y_1;

	limitX_2 = x_2;
	limitY_2 = y_2;
}

void Collider2D::initialize(const float x_1, const float x_2, const float y_1, const float y_2) {
	limitX_1 = x_1;
	limitY_1 = y_1;

	limitX_2 = x_2;
	limitY_2 = y_2;
}

Collider2D::~Collider2D() {
	limitX_1 = 0;
	limitX_2 = 0;

	limitY_1 = 0;
	limitY_2 = 0;
}

float Collider2D::getLeftLimit() {
	return limitX_1;
}

float Collider2D::getRightLimit() {
	return limitX_2;
}

float Collider2D::getTopLimit() {
	return limitY_1;
}

float Collider2D::getBottomLimit() {
	return limitY_2;
}

bool Collider2D::checkCollision(Collider2D& other) {
	if (limitX_1 < other.limitX_2 && limitX_2 > other.limitX_1 &&
		limitY_1 > other.limitY_2 && limitY_2 < other.limitY_1) {
		return true;
	}
	else
		return false;
}

void Collider2D::updateBoundaries(const float x_1, const float x_2, const float y_1, const float y_2) {
	limitX_1 = x_1;
	limitY_1 = y_1;

	limitX_2 = x_2;
	limitY_2 = y_2;
}

