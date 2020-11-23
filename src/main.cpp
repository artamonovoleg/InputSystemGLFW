#include <iostream>
#include <GLFW/glfw3.h>

#include "EventSystem.hpp"
#include "InputHandler.hpp"

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main()
{
    glfwInit();
    GLFWwindow* window = nullptr;
    const int width = 800;
    const int height = 600;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, "Events", nullptr, nullptr);
    glfwMakeContextCurrent(window);

//    glfwSetKeyCallback(window, key_callback);
    EventSystem::Init(window, WindowManager::GLFW_WM);

    while(!InputHandler::IsKeyDown(GLFW_KEY_ESCAPE))
    {
        if (InputHandler::IsKeyPressed(GLFW_KEY_E))
            std::cout << "E pressed" << std::endl;
        if (InputHandler::IsKeyReleased(GLFW_KEY_Q))
            std::cout << "Q released" << std::endl;
        if (InputHandler::IsKeyDown(GLFW_KEY_W))
            std::cout << "W down" << std::endl;
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == 1)
        EventSystem::HandleNewEvent(KeyPressedEvent(key));
    else
    if (action == 0)
        EventSystem::HandleNewEvent(KeyReleasedEvent(key));
}