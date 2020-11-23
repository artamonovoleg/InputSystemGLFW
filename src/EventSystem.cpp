//
// Created by artamonovoleg on 23.11.2020.
//

#include "EventSystem.hpp"
#include <GLFW/glfw3.h>

void EventSystem::HandleNewEvent(const Event &ev)
{
    switch (ev.category)
    {
        case EventCategory::KeyEvent:
            InputHandler::UpdateKeyState(static_cast<const KeyEvent&>(ev).GetKey(), static_cast<const KeyEvent&>(ev).GetState());
            break;
        case EventCategory::MouseWheelEvent:
            InputHandler::UpdateWheelState(static_cast<const MouseScrollEvent&>(ev).GetState());
            break;
        case EventCategory::MouseButtonEvent:
            InputHandler::UpdateButtonState(static_cast<const MouseButtonEvent&>(ev).GetButton(), static_cast<const MouseButtonEvent&>(ev).GetState());
            break;
        case EventCategory::None:
            break;
    }
}

void EventSystem::OnKeyAction(int key, int action)
{
    if (action == GLFW_PRESS)
        EventSystem::HandleNewEvent(KeyPressedEvent(key));
    else
    if (action == GLFW_RELEASE)
        EventSystem::HandleNewEvent(KeyReleasedEvent(key));
}

void EventSystem::OnButtonAction(int button, int action)
{
    if (action == GLFW_PRESS)
        EventSystem::HandleNewEvent(MousePressedEvent(button));
    else
    if (action == GLFW_RELEASE)
        EventSystem::HandleNewEvent(MouseReleasedEvent(button));
}

void EventSystem::OnWheelAction(double offset)
{
    if (offset > 0)
        EventSystem::HandleNewEvent(MouseScrollEvent(WheelState::SCROLL_UP));
    else
    if (offset < 0)
        EventSystem::HandleNewEvent(MouseScrollEvent(WheelState::SCROLL_DOWN));
}

void EventSystem::Init()
{
    glfwSetKeyCallback(glfwGetCurrentContext(), [](GLFWwindow* window, int key, int scancode, int action, int mods) { OnKeyAction(key, action); });
    glfwSetMouseButtonCallback(glfwGetCurrentContext(), [] (GLFWwindow* window, int button, int action, int mods) { OnButtonAction(button, action); });
    glfwSetScrollCallback(glfwGetCurrentContext(), [](GLFWwindow* window, double xoffset, double yoffset) { OnWheelAction(yoffset); });
}


