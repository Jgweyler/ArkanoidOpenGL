#ifndef __DRAWABLE_H__
#define __DRAWABLE_H__

#include <geometries\geometry.h>
#include <material.h>

#include <glm\glm.hpp>
	
class Drawable {
private:

	Geometry geometry_;
	Material material_;

public:
	Drawable();
	Drawable(Geometry &geometry, Material &material);
	~Drawable();
	void render(glm::mat4 projection, glm::mat4 view, glm::vec3 position, glm::vec3 cameraPos,  glm::vec3 lightPos);

};
#endif