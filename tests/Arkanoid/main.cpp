#include <window.h>
#include <gpu.h>
#include <geometries/cube.h>

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include<gameObjects/platform.h>
#include<scene.h>

Camera camera(glm::vec3(0.0f, 10.0f, 30.0f));
glm::vec3 lightPos(1.2f, 1.0f, 3.0);


//const uint32_t k_screen_width = 800;
//const uint32_t k_screen_height = 800;

float lastFrame = 0.0f;

int main(int argc, char* argv[]) {

	Window window(k_screen_width, k_screen_height, "Arkanoid");
	GPU gpu;

	Cube cube(glm::vec3(0.0f, 0.0f, 0.0f), 0.5f);

	gpu.createVertexData(cube);

	Shader shader_light("../tests/Arkanoid/light.vs", "../tests/Arkanoid/light.fs");

	Material material("../tests/Arkanoid/shader.vs", "../tests/Arkanoid/shader.fs",
		"../tests/Arkanoid/Textures/diffuse.jpg", "../tests/Arkanoid/Textures/specular.jpg");

	Drawable drawable(cube, material);
	Platform player(drawable);

	Scene scene;
	scene.addGameObject(&player);

	glm::mat4 projection = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(camera.getFOV()), (float)k_screen_width / (float)k_screen_height, 0.1f, 100.0f);

	glm::mat4 view = camera.getViewMatrix();


	//glfwSetCursorPosCallback(window, onMouse);
	//glfwSetScrollCallback(window, onScroll);
	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);


	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);

	while (!window.shouldClose()) {

		float currentFrame = (float) glfwGetTime();
		float deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		window.handleInput(player, deltaTime);
		scene.update(deltaTime);
		scene.render();

		window.swapBuffers();
		glfwPollEvents();
	}

	return 0;
}