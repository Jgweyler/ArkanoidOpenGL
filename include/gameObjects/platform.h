#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#include<gameObject.h>
#include<drawable.h>

const float platform_speed = 10.0f;

class Platform : public GameObject {
private:
	Drawable drawable;
	float platformSpeed;

	Platform();

public:

	enum class Movement {
		Left = 0,
		Right = 1,
	};

	Platform(Drawable &platformDrawable);
	~Platform() {};

	void update(const float dt);
	void render(glm::mat4 projection, glm::mat4 view, glm::vec3 cameraPos, glm::vec3 lightPos);
	void handleKeyboard(const Movement direction, const float dt);

};
#endif