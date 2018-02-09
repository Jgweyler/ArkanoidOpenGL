#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include<gameObjects\platform.h>

#include <cstdint>

class Window {

private:
	uint32_t width;
	uint32_t height;

	GLFWwindow* window;

	Window();
	static void onChangeFrameBufferSize(GLFWwindow* window, const int32_t width, const int32_t height);


public:
	Window(const uint32_t window_width, const uint32_t window_height, const char* window_name);
	~Window();
	void enableMouseCursor(const bool enable);
	bool shouldClose();
	void swapBuffers();

	void handleInput(Platform &player, const float dt);
	void render(Platform &player, glm::mat4 projection, glm::mat4 view, glm::vec3 cameraPos, glm::vec3 lightPos);
};



#endif