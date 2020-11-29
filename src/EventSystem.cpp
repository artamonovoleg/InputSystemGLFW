//
// Created by artamonovoleg on 23.11.2020.
//

#include <GLFW/glfw3.h>
#include <chrono>
#include <iostream>

#include "EventSystem.hpp"
#include "WindowEvent.hpp"

bool EventSystem::m_WindowCanClose = true;
std::unordered_map<EventCategory, std::list<std::function<void(const Event&)>>> EventSystem::listeners;

void EventSystem::SendEvent(const Event &ev)
{
    for (auto const& listener : listeners[ev.category])
    {
        listener(ev);
    }
//
//    switch (ev.category)
//    {
//        case EventCategory::KeyEvent:
//            InputHandler::UpdateKeyState(dynamic_cast<const KeyEvent&>(ev).GetKey(), dynamic_cast<const KeyEvent&>(ev).GetState());
//            break;
//        case EventCategory::MouseWheelEvent:
//            InputHandler::UpdateWheelState(dynamic_cast<const MouseScrollEvent&>(ev).GetState());
//            break;
//        case EventCategory::MouseButtonEvent:
//            InputHandler::UpdateButtonState(dynamic_cast<const MouseButtonEvent&>(ev).GetButton(), dynamic_cast<const MouseButtonEvent&>(ev).GetState());
//            break;
//        case EventCategory::MouseMoveEvent:
//            InputHandler::UpdateCursorPosition(dynamic_cast<const MouseMoveEvent&>(ev).GetPos());
//            break;
//        case EventCategory::WindowResizeEvent:
//            glViewport(0, 0, dynamic_cast<const WindowResizeEvent&>(ev).GetWidth(), dynamic_cast<const WindowResizeEvent&>(ev).GetHeight());
//            break;
//        case EventCategory::WindowCloseEvent:
//            if (m_WindowCanClose)
//                glfwSetWindowShouldClose(glfwGetCurrentContext(), GLFW_TRUE);
//            break;
//        case EventCategory::None:
//            break;
//    }
}

void EventSystem::WindowCanClose(bool value)
{
    m_WindowCanClose = value;
}

void EventSystem::OnKeyAction(int key, int action)
{
    if (action == GLFW_PRESS)
        EventSystem::SendEvent(KeyPressedEvent(key));
    else
    if (action == GLFW_RELEASE)
        EventSystem::SendEvent(KeyReleasedEvent(key));
}

void EventSystem::OnButtonAction(int button, int action)
{
    if (action == GLFW_PRESS)
        EventSystem::SendEvent(MousePressedEvent(button));
    else
    if (action == GLFW_RELEASE)
        EventSystem::SendEvent(MouseReleasedEvent(button));
}

void EventSystem::OnWheelAction(double offset)
{
    if (offset > 0)
        EventSystem::SendEvent(MouseScrollEvent(WheelState::SCROLL_UP));
    else
    if (offset < 0)
        EventSystem::SendEvent(MouseScrollEvent(WheelState::SCROLL_DOWN));
}

void EventSystem::OnCursorAction(double x, double y)
{
    EventSystem::SendEvent(MouseMoveEvent({ x, y }));
}

void EventSystem::OnWindowResizeAction(int width, int height)
{
    EventSystem::SendEvent(WindowResizeEvent(width, height));
}

void EventSystem::OnWindowCloseAction()
{
    EventSystem::SendEvent(WindowCloseEvent());
}

void EventSystem::Init()
{
    glfwSetKeyCallback(glfwGetCurrentContext(), [](GLFWwindow* window, int key, int scancode, int action, int mods)
    { OnKeyAction(key, action); });
    glfwSetMouseButtonCallback(glfwGetCurrentContext(), [](GLFWwindow* window, int button, int action, int mods)
    { OnButtonAction(button, action); });
    glfwSetScrollCallback(glfwGetCurrentContext(), [](GLFWwindow* window, double xoffset, double yoffset)
    { OnWheelAction(yoffset); });
    glfwSetCursorPosCallback(glfwGetCurrentContext(), [](GLFWwindow* window, double xpos, double ypos)
    { OnCursorAction(xpos, ypos); });
    glfwSetFramebufferSizeCallback(glfwGetCurrentContext(), [](GLFWwindow* window, int width, int height)
    { OnWindowResizeAction(width, height); });
    glfwSetWindowCloseCallback(glfwGetCurrentContext(), [](GLFWwindow* window)
    { OnWindowCloseAction(); });
}

bool EventSystem::IsWindowClose()
{
    return (m_WindowCanClose && glfwWindowShouldClose(glfwGetCurrentContext()));
}

