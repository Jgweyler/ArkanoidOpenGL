#include <texture.h>

#include <glad/glad.h>

#define STB_IMAGE_IMPLEMENTATION
#include<stb_image.h>

#include <iostream>

Texture::Texture(const char * path) {

	initialize(path);
	
}

Texture::~Texture() {
	release();
}

void Texture::initialize(const char * texPath) {

	glGenTextures(1, &tex_);
	glBindTexture(GL_TEXTURE_2D, tex_);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nChannels;

	unsigned char* data = stbi_load(texPath, &width, &height, &nChannels, 0);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

	}
	else {
		std::cout << "Failed load texture: " << texPath << std::endl;
	}
}

void Texture::release() {
	glDeleteTextures(1, &tex_);
	tex_ = 0;
}

void Texture::bind() const {
	glBindTexture(GL_TEXTURE_2D, tex_);
}
