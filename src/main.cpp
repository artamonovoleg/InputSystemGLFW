#include <iostream>
#include <GLFW/glfw3.h>

#include "EventSystem.hpp"
#include "InputSystem.hpp"

void OnWindowClose(bool& isClosed)
{
    isClosed = true;
}

int main()
{
    glfwInit();
    const int width = 800;
    const int height = 600;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(width, height, "Events", nullptr, nullptr);
    bool isClosed = false;

    glfwMakeContextCurrent(window);

    EventSystem::Init();
    InputSystem::Init();

    // Add simple listener
    EventSystem::AddListener(EventCategory::WindowCloseEvent, [&](const Event& event) { OnWindowClose(isClosed); });

    while(!isClosed)
    {
        if (InputSystem::IsKeyPressed(GLFW_KEY_E))
            std::cout << "E pressed" << std::endl;
        if (InputSystem::IsKeyReleased(GLFW_KEY_Q))
            std::cout << "Q released" << std::endl;
        if (InputSystem::IsKeyDown(GLFW_KEY_W))
            std::cout << "W down" << std::endl;
        if (InputSystem::IsButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
            std::cout << "LMB pressed" << std::endl;
        if (InputSystem::IsButtonDown(GLFW_MOUSE_BUTTON_RIGHT))
            std::cout << "RMB held" << std::endl;
        if (InputSystem::IsButtonReleased(GLFW_MOUSE_BUTTON_MIDDLE))
            std::cout << "Wheel released" << std::endl;
        if (InputSystem::IsScrollingUp())
            std::cout << "Scroll up" << std::endl;
        if (InputSystem::IsScrollingDown())
            std::cout << "Scroll down" << std::endl;
        if (InputSystem::GetMousePosition().x > width / 2 && InputSystem::GetMousePosition().y > height / 2)
            std::cout << "Cursor in second quoter of screen. Pos: " << InputSystem::GetMousePosition().x << " " << InputSystem::GetMousePosition().y << std::endl;
        EventSystem::PollEvents();
    }

    glfwTerminate();
    return 0;
}
