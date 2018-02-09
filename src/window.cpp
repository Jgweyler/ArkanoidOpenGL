#include <window.h>

#include<iostream>




Window::Window(const uint32_t window_width, const uint32_t window_height, const char* window_name) {

	width = window_width;
	height = window_height;

	if (!glfwInit()) {
		std::cout << "Error Initializing GLFW" << std::endl;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(window_width, window_height, window_name, NULL, NULL);

	if (!window) {
		std::cout << "Error creating window" << std::endl;
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);

	//Try to connect to OPENGL
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Error Initializing GLAD" << std::endl;
	}

	glfwSetFramebufferSizeCallback(window, onChangeFrameBufferSize);
}

Window::~Window() {
	glfwTerminate();
}

void Window::onChangeFrameBufferSize(GLFWwindow* window, const int32_t width, const int32_t height) {
	glViewport(0, 0, width, height);
}

void Window::enableMouseCursor(const bool enable) {
	if(!enable)
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	else
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

bool  Window::shouldClose() {
	return glfwWindowShouldClose(window);
}

void Window::swapBuffers() {
	glfwSwapBuffers(window);
}

void Window::handleInput(Platform &player, const float dt) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		player.handleKeyboard(Platform::Movement::Left, dt);

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		player.handleKeyboard(Platform::Movement::Right, dt);

}

void Window::render(Platform &player, glm::mat4 projection, glm::mat4 view, glm::vec3 cameraPos, glm::vec3 lightPos) {
	

	player.render(projection, view, cameraPos, lightPos);
}

