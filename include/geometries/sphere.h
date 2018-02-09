#ifndef __SPHERE_H__
#define __SPHERE_H__

#include <geometries\geometry.h>
#define _USE_MATH_DEFINES
#include <math.h>



class Sphere : public Geometry {

private:

	//TODO: Estas constantes no serán constantes en un futuro, porque dependen del número de atributos de vértice y obviamente 
	//dependerá de la cantidad de información que el programador quiera aportar.

	const uint32_t VERTEX_DATA_SIZE = 20; // 4 vertices + 2 uv coord per vertice.
	static const uint32_t INDICES_DATA_SIZE = 6;

	Sphere();
	void Sphere::generateVerts(const uint32_t slices, const uint32_t stacks, const uint32_t radius);

public:

	Sphere(const float radius);
	~Sphere();
};
#endif