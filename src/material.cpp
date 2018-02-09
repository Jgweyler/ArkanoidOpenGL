#include <material.h>

Material::Material() {

}

Material::Material(Shader & shader, Texture & diffuse, Texture & specular) {
	shader_ = shader;
	texture_diffuse = diffuse;
	texture_specular = specular;
}

Material::Material(const char* vertexPath, const char* fragmentPath, const char * diffuseTexPath, const char * specularTexPath) {
	
	shader_.initialize(vertexPath, fragmentPath);
	texture_diffuse.initialize(diffuseTexPath);
	texture_specular.initialize(specularTexPath);
}
Material::~Material() {
	shader_.~Shader();
	texture_diffuse.~Texture();
	texture_specular.~Texture();
}

void Material::use() const {
	shader_.use();
}

void Material::set(const char* name, const bool value) const {
	shader_.set(name, value);
}

void Material::set(const char* name, const int value) const {
	shader_.set(name, value);
}

void Material::set(const char* name, const float value) const {
	shader_.set(name, value);
}
void Material::set(const char* name, const float value1, const float value2) const {
	shader_.set(name, value1, value2);
}
void Material::set(const char* name, const float value1, const float value2, const float value3) const{
	shader_.set(name, value1, value2, value3);
}
void Material::set(const char* name, const float value1, const float value2, const float value3, const float value4) const{
	shader_.set(name, value1, value2, value3, value4);
}

void Material::set(const char* name, const glm::vec2& value) const{
	shader_.set(name, value);
}
void Material::set(const char* name, const glm::vec3& value) const{
	shader_.set(name, value);
}
void Material::set(const char* name, const glm::vec4& value) const{
	shader_.set(name, value);
}
void Material::set(const char* name, const glm::mat2& value) const{
	shader_.set(name, value);
}
void Material::set(const char* name, const glm::mat3& value) const{
	shader_.set(name, value);
}
void Material::set(const char* name, const glm::mat4& value) const{
	shader_.set(name, value);
}


void Material::bindDiffTexture()const {
	texture_diffuse.bind();
}

void Material::bindSpecTexture() const {
	texture_specular.bind();
}