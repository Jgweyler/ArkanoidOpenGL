#ifndef __COLLIDER2D_H__
#define __COLLIDER2D_H__

#include <component.h>
#include <gameObject.h>

#include <stdint.h>

class Collider2D : public Component {
private:
	float limitX_1; //Left coord
	float limitX_2; //Right coord

	float limitY_1; //Top coord
	float limitY_2; //Bottom coord

public:
	Collider2D();
	Collider2D(const float x_1, const float x_2, const float y_1, const float y_2);
	void initialize(const float x_1, const float x_2, const float y_1, const float y_2);
	~Collider2D();

	float getLeftLimit();
	float getRightLimit();
	float getTopLimit();
	float getBottomLimit();



	bool checkCollision(Collider2D& other);
	void updateBoundaries(const float x_1, const float x_2, const float y_1, const float y_2);

	
};
#endif // ! __COLLIDER2D_H__
