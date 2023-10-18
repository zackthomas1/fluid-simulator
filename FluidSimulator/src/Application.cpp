#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

//
void framebuffer_size_callback(GLFWwindow* window, int width, int height);


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
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
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

	glViewport(0, 0, 800, 600); 

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// render loop
	// -----------
	while (!glfwWindowShouldClose(window))
	{
		// glfw: swap buffers and poll IO events (key pressed/released, mouse moved)
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