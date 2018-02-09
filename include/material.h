#ifndef __MATERIAL_H__
#define __MATERIAL_H__
#include <shader.h>
#include<texture.h>

class Material {
private:
	Shader shader_;
	Texture texture_diffuse;
	Texture texture_specular;

public:
	
	Material();
	Material(const char* vertexPath, const char* fragmentPath, const char * diffuseTexPath, const char * specularTexPath);
	Material(Shader& shader, Texture& diffuse, Texture& specular);
	~Material();

	void use() const;

	void set(const char* name, const bool value) const;
	void set(const char* name, const int value) const;
	void set(const char* name, const float value) const;
	void set(const char* name, const float value1, const float value2) const;
	void set(const char* name, const float value1, const float value2, const float value3) const;
	void set(const char* name, const float value1, const float value2, const float value3, const float value4) const;

	void set(const char* name, const glm::vec2& value) const;
	void set(const char* name, const glm::vec3& value) const;
	void set(const char* name, const glm::vec4& value) const;
	void set(const char* name, const glm::mat2& value) const;
	void set(const char* name, const glm::mat3& value) const;
	void set(const char* name, const glm::mat4& value) const;

	void bindDiffTexture()const;
	void bindSpecTexture() const;


};
#endif