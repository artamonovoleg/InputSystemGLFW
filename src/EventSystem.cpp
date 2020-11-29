//
// Created by artamonovoleg on 23.11.2020.
//

#include <GLFW/glfw3.h>
#include <chrono>
#include <iostream>

#include "EventSystem.hpp"
#include "WindowEvent.hpp"

std::unordered_map<EventCategory, std::list<std::function<void(const Event&)>>> EventSystem::listeners;

void EventSystem::AddListener(EventCategory eventId, const std::function<void(const Event &)> &listener)
{
    listeners[eventId].push_back(listener);
}

void EventSystem::SendEvent(const Event &ev)
{
    for (auto const& listener : listeners[ev.category])
        listener(ev);
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
    EventSystem::SendEvent(WindowCloseEvent {});
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

void EventSystem::PollEvents()
{
    glfwPollEvents();
}
