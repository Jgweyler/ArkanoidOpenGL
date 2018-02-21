#include <window.h>
#include <gpu.h>
#include <geometries/cube.h>
#include <geometries/sphere.h>

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include<gameObjects/platform.h>
#include <gameObjects/ball.h>
#include <gameObjects\level.h>
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
	Sphere sphere(1.0f);

	gpu.createVertexData(cube);
	gpu.createVertexData(sphere);

	Shader shader_light("../tests/Arkanoid/light.vs", "../tests/Arkanoid/light.fs");

	Material material("../tests/Arkanoid/shader.vs", "../tests/Arkanoid/shader.fs",
		"../tests/Arkanoid/Textures/diffuse_1.jpg", "../tests/Arkanoid/Textures/specular_1.jpg");

	Material sphereMaterial("../tests/Arkanoid/Shaders/shader.vs", "../tests/Arkanoid/Shaders/shader.fs");

	Drawable drawable_cube(&cube, &material);
	Drawable drawable_sphere(&sphere, &sphereMaterial);

	Platform player(drawable_cube);
	Ball ball(&drawable_sphere, &player);

	Wall wall_left(&drawable_cube, glm::vec3(-11.5f, 0.0f, 0.0f));
	Wall wall_right(&drawable_cube, glm::vec3(11.5f, 0.0f, 0.0f));
	Wall wall_top(&drawable_cube, glm::vec3(0.0f, 0.0f, 0.0f));

	LevelBoundaries walls(&wall_top, &wall_left, &wall_right);
	Level level(&drawable_cube, &ball, "../tests/Arkanoid/Levels/level1.txt");

	Scene scene;
	scene.addGameObject(&player);
	scene.addGameObject(&ball);
	scene.addGameObject(&walls);
	scene.addGameObject(&level);

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

		ball.setCollideThisFrame(false);

		window.handleInput(player, ball, deltaTime);
		scene.update(deltaTime);
		scene.render();

		window.swapBuffers();
		glfwPollEvents();
	}

	return 0;
}