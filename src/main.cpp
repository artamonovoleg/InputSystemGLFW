#include <iostream>
#include <GLFW/glfw3.h>

#include "EventSystem.hpp"
#include "InputHandler.hpp"
#include "WindowEvent.hpp"

void OnWindowResizeEvent(const WindowResizeEvent& event)
{
    std::cout << "width: " << event.GetWidth() << " height: " << event.GetHeight() << std::endl;
}

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
    // Later it can be used to disable closing while load smth or anything else. Default value: true
    EventSystem::WindowCanClose(true);

    // This is how you can add event listener. Now with cast. rewrite later.
    EventSystem::AddListener(EventCategory::WindowResizeEvent, [&](const Event& event)
                             { OnWindowResizeEvent(dynamic_cast<const WindowResizeEvent&>(event)); });
    InputHandler input;
    while(!input.IsKeyDown(GLFW_KEY_ESCAPE) && !EventSystem::IsWindowClose())
    {
        if (input.IsKeyPressed(GLFW_KEY_E))
            std::cout << "E pressed" << std::endl;
        if (input.IsKeyReleased(GLFW_KEY_Q))
            std::cout << "Q released" << std::endl;
        if (input.IsKeyDown(GLFW_KEY_W))
            std::cout << "W down" << std::endl;
        if (input.IsButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
            std::cout << "LMB pressed" << std::endl;
        if (input.IsButtonDown(GLFW_MOUSE_BUTTON_RIGHT))
            std::cout << "RMB held" << std::endl;
        if (input.IsButtonReleased(GLFW_MOUSE_BUTTON_MIDDLE))
            std::cout << "Wheel released" << std::endl;
        if (input.IsScrollingUp())
            std::cout << "Scroll up" << std::endl;
        if (input.IsScrollingDown())
            std::cout << "Scroll down" << std::endl;
        if (input.GetMousePosition().x > width / 2 && input.GetMousePosition().y > height / 2)
            std::cout << "Cursor in second quoter of screen. Pos: " << input.GetMousePosition().x << " " << input.GetMousePosition().y << std::endl;
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
