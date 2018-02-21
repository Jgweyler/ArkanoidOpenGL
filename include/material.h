#ifndef __MATERIAL_H__
#define __MATERIAL_H__
#include <shader.h>
#include<texture.h>
#include <stdint.h>

const uint32_t MAX_TEXTURES = 3;

class Material {
private:
	Shader shader_;
	uint32_t selected_Texture;
	uint32_t nTextures;
	Texture diffuse_textures[MAX_TEXTURES];
	Texture specular_textures[MAX_TEXTURES];

public:
	
	Material();
	Material(Shader& shader);
	Material(const char* vertexPath, const char* fragmentPath);
	Material(const char* vertexPath, const char* fragmentPath, const char * diffuseTexPath, const char * specularTexPath);
	Material(Shader& shader, Texture& diffuse, Texture& specular);
	~Material();
	
	void addTexture(Texture& texture_diffuse, Texture& texture_specular);
	void changeSelectedTexture(const uint32_t select);

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