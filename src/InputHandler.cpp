//
// Created by artamonovoleg on 23.11.2020.
//

#include "InputHandler.hpp"
#include "EventSystem.hpp"

void InputHandler::OnKeyEvent(const KeyEvent &event)
{
    m_Keys[event.GetKey()] = event.GetState();
}

void InputHandler::OnButtonEvent(const MouseButtonEvent &event)
{
    m_Buttons[event.GetButton()] = event.GetState();
}

void InputHandler::OnScrollEvent(const MouseScrollEvent &event)
{
    m_WheelState = event.GetState();
}

void InputHandler::OnMouseMoveEvent(const MouseMoveEvent &event)
{
    m_CursorPos = event.GetPos();
}

InputHandler::InputHandler()
{
    EventSystem::AddListener(EventCategory::KeyEvent, [&](const Event& event) { OnKeyEvent(dynamic_cast<const KeyEvent&>(event)); });
    EventSystem::AddListener(EventCategory::MouseButtonEvent, [&](const Event& event) { OnButtonEvent(dynamic_cast<const MouseButtonEvent&>(event)); });
    EventSystem::AddListener(EventCategory::MouseMoveEvent, [&](const Event& event) { OnMouseMoveEvent(dynamic_cast<const MouseMoveEvent&>(event)); });
    EventSystem::AddListener(EventCategory::MouseWheelEvent, [&](const Event& event) { OnScrollEvent(dynamic_cast<const MouseScrollEvent&>(event)); });
}

bool InputHandler::IsPressed(int value, PressState *buffer)
{
    bool ret = false;
    if (buffer[value] == PressState::PRESSED)
    {
        ret = true;
        buffer[value] = PressState::HELD;
    }
    return ret;
}

bool InputHandler::IsDown(int value, PressState *buffer)
{
    return (buffer[value] == PressState::PRESSED || buffer[value] == PressState::HELD);
}

bool InputHandler::IsReleased(int value, PressState *buffer)
{
    bool ret = false;
    if (buffer[value] == PressState::RELEASED)
    {
        ret = true;
        buffer[value] = PressState::NONE;
    }
    return ret;
}

bool InputHandler::IsKeyPressed(int key) { return IsPressed(key, m_Keys); }
bool InputHandler::IsKeyDown(int key) { return IsDown(key, m_Keys); }
bool InputHandler::IsKeyReleased(int key) { return IsReleased(key, m_Keys); }

bool InputHandler::IsButtonPressed(int button) { return IsPressed(button, m_Buttons); }
bool InputHandler::IsButtonDown(int button) { return IsDown(button, m_Buttons); }
bool InputHandler::IsButtonReleased(int button) { return IsReleased(button, m_Buttons); }

bool InputHandler::IsScrollingUp()
{
    bool ret = false;
    if (m_WheelState == WheelState::SCROLL_UP)
    {
        ret = true;
        m_WheelState = WheelState::NONE;
    }
    return ret;
}

bool InputHandler::IsScrollingDown()
{
    bool ret = false;
    if (m_WheelState == WheelState::SCROLL_DOWN)
    {
        ret = true;
        m_WheelState = WheelState::NONE;
    }
    return ret;
}

CursorPos InputHandler::GetMousePosition() { return m_CursorPos; }