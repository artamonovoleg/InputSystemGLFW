//
// Created by artamonovoleg on 23.11.2020.
//

#include <GLFW/glfw3.h>

#include "EventSystem.hpp"
#include "WindowEvent.hpp"

bool EventSystem::m_WindowCanClose = false;

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
        case EventCategory::MouseMoveEvent:
            InputHandler::UpdateCursorPosition(static_cast<const MouseMoveEvent&>(ev).GetPos());
            break;
        case EventCategory::WindowResizeEvent:
            glViewport(0, 0, static_cast<const WindowResizeEvent&>(ev).GetWidth(), static_cast<const WindowResizeEvent&>(ev).GetHeight());
            break;
        case EventCategory::WindowCloseEvent:
            if (m_WindowCanClose)
                glfwSetWindowShouldClose(glfwGetCurrentContext(), GLFW_TRUE);
            break;
        case EventCategory::None:
            break;
    }
}

void EventSystem::WindowCanClose(bool value)
{
    m_WindowCanClose = value;
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

void EventSystem::OnCursorAction(double x, double y)
{
    EventSystem::HandleNewEvent(MouseMoveEvent({ x, y }));
}

void EventSystem::OnWindowResizeAction(int width, int height)
{
    EventSystem::HandleNewEvent(WindowResizeEvent(width, height));
}

void EventSystem::OnWindowCloseAction()
{
    EventSystem::HandleNewEvent(WindowCloseEvent());
}

void EventSystem::Init()
{
    glfwSetKeyCallback(glfwGetCurrentContext(), [](GLFWwindow* window, int key, int scancode, int action, int mods) { OnKeyAction(key, action); });
    glfwSetMouseButtonCallback(glfwGetCurrentContext(), [] (GLFWwindow* window, int button, int action, int mods) { OnButtonAction(button, action); });
    glfwSetScrollCallback(glfwGetCurrentContext(), [](GLFWwindow* window, double xoffset, double yoffset) { OnWheelAction(yoffset); });
    glfwSetCursorPosCallback(glfwGetCurrentContext(), [](GLFWwindow* window, double xpos, double ypos) { OnCursorAction(xpos, ypos); });
    glfwSetFramebufferSizeCallback(glfwGetCurrentContext(), [](GLFWwindow* window, int width, int height) { OnWindowResizeAction(width, height); });
    glfwSetWindowCloseCallback(glfwGetCurrentContext(), [](GLFWwindow* window) { OnWindowCloseAction(); });
}

bool EventSystem::IsWindowClose()
{
    return (m_WindowCanClose && glfwWindowShouldClose(glfwGetCurrentContext()));
}






