#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include <cstdint>

class Texture {
private:
	uint32_t tex_;

	void release();

public:
	Texture(const char * path);
	Texture() { tex_ = 0; };
	~Texture();

	void initialize(const char * texPath);
	void bind() const;
};

#endif