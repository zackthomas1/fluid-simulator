#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

//
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800; 
const unsigned int SCR_HEIGHT = 600;

int main(int argc, char** argv)
{
	// glfw: initialize and configure
	// ------------------------------
	glfwInit(); 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); 
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// create window object
	// --------------------
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "FluidSim", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl; 
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// initialize GLAD: load all OpengGL function pointers
	// ---------------------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl; 
		return -1;
	}

	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// render loop
	// -----------
	while (!glfwWindowShouldClose(window))
	{
		// input
		processInput(window);

		// rendering commands here
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);	// state-setting
		glClear(GL_COLOR_BUFFER_BIT);			// state-using

		// glfw: swap buffers and poll IO events (key pressed/released, mouse moved)
		// check and call events and swap the buffers
		glfwSwapBuffers(window); 
		glfwPollEvents();
	}

	// clean up/delete all GLFW resources 
	// ----------------------------------
	glfwTerminate(); 
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}