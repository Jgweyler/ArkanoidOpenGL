#include <material.h>

Material::Material() {
	nTextures = 0;
	selected_Texture = 0;

	/*for (uint32_t i = 0; i < MAX_TEXTURES; i++) {
		diffuse_textures[i] = NULL;
		specular_textures[i] = NULL;
	}*/
}

Material::Material(Shader & shader, Texture & diffuse, Texture & specular) {
	
	nTextures = 0;
	selected_Texture = 0;

	shader_ = shader;
	diffuse_textures[selected_Texture] = diffuse;
	specular_textures[selected_Texture] = specular;
}

Material::Material(Shader& shader) {
	selected_Texture = 0;
	nTextures = 0;
	shader_ = shader;
}

Material::Material(const char* vertexPath, const char* fragmentPath) {
	selected_Texture = 0;
	nTextures = 0;
	shader_.initialize(vertexPath, fragmentPath);
}

Material::Material(const char* vertexPath, const char* fragmentPath, const char * diffuseTexPath, const char * specularTexPath) {
	
	selected_Texture = 0;
	nTextures = 1;
	shader_.initialize(vertexPath, fragmentPath);
	diffuse_textures[selected_Texture].initialize(diffuseTexPath);
	specular_textures [selected_Texture].initialize(specularTexPath);
}
Material::~Material() {

}

void Material::addTexture(Texture& texture_diffuse, Texture& texture_specular) {
	if (nTextures < MAX_TEXTURES - 1) {
		diffuse_textures[nTextures] = texture_diffuse;
		specular_textures[nTextures] = texture_specular;
		nTextures++;
	}
}


void Material::changeSelectedTexture(const uint32_t select) {
	if (select >= MAX_TEXTURES)
		selected_Texture = nTextures;
	else
		selected_Texture = select;
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
	if(nTextures > 0)
		diffuse_textures[selected_Texture].bind();
}

void Material::bindSpecTexture() const {
	if (nTextures > 0)
		specular_textures[selected_Texture].bind();
}