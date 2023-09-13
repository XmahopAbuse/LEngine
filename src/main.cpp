#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int g_windowSizeX = 640;
int g_windowSizeY = 480;

void glfwWindowSizeCallback(GLFWwindow* pwindow, int width, int height) 
{
    g_windowSizeX = width;
    g_windowSizeY = height;
    glViewport(0, 0, width, height);
    std::cout << "Resize window " << std::endl;
}

void glfwKeyCallback(GLFWwindow* pwindow, int key, int scancode, int action, int mode) 
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(pwindow, true);
    }
}

int main(void)
{
    GLFWwindow* pwindow;

    /* Initialize the library */
    if (!glfwInit())
        return -1;


    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    //Минорная
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    //Установка профайла для которого создается контекст
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    /* Create a windowed mode window and its OpenGL context */
    pwindow = glfwCreateWindow(g_windowSizeX, g_windowSizeY, "LEngine", nullptr, nullptr);
    if (!pwindow)
    {
        glfwTerminate();
        return -1;
    }

    glfwSetWindowSizeCallback(pwindow, glfwWindowSizeCallback);
    glfwSetKeyCallback(pwindow, glfwKeyCallback);


    /* Make the window's context current */
    glfwMakeContextCurrent(pwindow);

    if (!gladLoadGL()) 
    {
        std::cout << "Error" << std::endl;
        return 1;
    }

    std::cout << "OpenGL: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;

    glClearColor(0, 1, 0, 1);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(pwindow))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(pwindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}