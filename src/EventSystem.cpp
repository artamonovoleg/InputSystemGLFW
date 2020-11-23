//
// Created by artamonovoleg on 23.11.2020.
//

#include "EventSystem.hpp"
#include <GLFW/glfw3.h>

void EventSystem::KeyBoardFun(int key, int action)
{
    if (action == 1)
        EventSystem::HandleNewEvent(KeyPressedEvent(key));
    else
    if (action == 0)
        EventSystem::HandleNewEvent(KeyReleasedEvent(key));
}

void EventSystem::Init(void *window, WindowManager wm)
{
    switch (wm)
    {
        case WindowManager::GLFW_WM:
        {
            glfwSetKeyCallback((GLFWwindow*)window, [](GLFWwindow* window, int key, int scancode, int action, int mods) { KeyBoardFun(key, action); });
        }
            break;
    }
}


