#include <iostream>
#include <GLFW/glfw3.h>

#include "EventSystem.hpp"
#include "InputHandler.hpp"

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

    EventSystem::Init();
    EventSystem::WindowCanClose(true); // Later it can be used to disable closing while load smth or anything else

    while(!InputHandler::IsKeyDown(GLFW_KEY_ESCAPE) && !EventSystem::IsWindowClose())
    {
        if (InputHandler::IsKeyPressed(GLFW_KEY_E))
            std::cout << "E pressed" << std::endl;
        if (InputHandler::IsKeyReleased(GLFW_KEY_Q))
            std::cout << "Q released" << std::endl;
        if (InputHandler::IsKeyDown(GLFW_KEY_W))
            std::cout << "W down" << std::endl;
        if (InputHandler::IsButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
            std::cout << "LMB pressed" << std::endl;
        if (InputHandler::IsButtonDown(GLFW_MOUSE_BUTTON_RIGHT))
            std::cout << "RMB held" << std::endl;
        if (InputHandler::IsButtonReleased(GLFW_MOUSE_BUTTON_MIDDLE))
            std::cout << "Wheel released" << std::endl;
        if (InputHandler::IsScrollingUp())
            std::cout << "Scroll up" << std::endl;
        if (InputHandler::IsScrollingDown())
            std::cout << "Scroll down" << std::endl;
        if (InputHandler::GetMousePosition().x > width / 2 && InputHandler::GetMousePosition().y > height / 2)
            std::cout << "Cursor in second quoter of screen. Pos: " << InputHandler::GetMousePosition().x << " " << InputHandler::GetMousePosition().y << std::endl;
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
