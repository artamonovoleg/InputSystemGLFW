//
// Created by artamonovoleg on 23.11.2020.
//

#include "InputSystem.hpp"
#include "EventSystem.hpp"

PressState InputSystem::m_Keys[1024] = { PressState::NONE };
PressState InputSystem::m_Buttons[10] = { PressState::NONE };
WheelState InputSystem::m_WheelState = { WheelState::NONE };
CursorPos InputSystem::m_CursorPos = { 0, 0 };

void InputSystem::OnKeyEvent(const Event &event)
{
    const auto& key_event = dynamic_cast<const KeyEvent&>(event);
    m_Keys[key_event.GetKey()] = key_event.GetState();
}

void InputSystem::OnButtonEvent(const Event &event)
{
    const auto& button_event = dynamic_cast<const MouseButtonEvent&>(event);
    m_Buttons[button_event.GetButton()] = button_event.GetState();
}

void InputSystem::OnScrollEvent(const Event &event)
{
    const auto& scroll_event = dynamic_cast<const MouseScrollEvent&>(event);
    m_WheelState = scroll_event.GetState();
}

void InputSystem::OnMouseMoveEvent(const Event &event)
{
    const auto& mouse_move_event = dynamic_cast<const MouseMoveEvent&>(event);
    m_CursorPos = mouse_move_event.GetPos();
}

void InputSystem::Init()
{
    EventSystem::AddListener(EventCategory::KeyEvent, OnKeyEvent);
    EventSystem::AddListener(EventCategory::MouseButtonEvent, OnButtonEvent);
    EventSystem::AddListener(EventCategory::MouseMoveEvent, OnMouseMoveEvent);
    EventSystem::AddListener(EventCategory::MouseWheelEvent, OnScrollEvent);
}

bool InputSystem::IsPressed(int value, PressState *buffer)
{
    bool ret = false;
    if (buffer[value] == PressState::PRESSED)
    {
        ret = true;
        buffer[value] = PressState::HELD;
    }
    return ret;
}

bool InputSystem::IsDown(int value, PressState *buffer)
{
    return (buffer[value] == PressState::PRESSED || buffer[value] == PressState::HELD);
}

bool InputSystem::IsReleased(int value, PressState *buffer)
{
    bool ret = false;
    if (buffer[value] == PressState::RELEASED)
    {
        ret = true;
        buffer[value] = PressState::NONE;
    }
    return ret;
}

bool InputSystem::IsKeyPressed(int key) { return IsPressed(key, m_Keys); }
bool InputSystem::IsKeyDown(int key) { return IsDown(key, m_Keys); }
bool InputSystem::IsKeyReleased(int key) { return IsReleased(key, m_Keys); }

bool InputSystem::IsButtonPressed(int button) { return IsPressed(button, m_Buttons); }
bool InputSystem::IsButtonDown(int button) { return IsDown(button, m_Buttons); }
bool InputSystem::IsButtonReleased(int button) { return IsReleased(button, m_Buttons); }

bool InputSystem::IsScrollingUp()
{
    bool ret = false;
    if (m_WheelState == WheelState::SCROLL_UP)
    {
        ret = true;
        m_WheelState = WheelState::NONE;
    }
    return ret;
}

bool InputSystem::IsScrollingDown()
{
    bool ret = false;
    if (m_WheelState == WheelState::SCROLL_DOWN)
    {
        ret = true;
        m_WheelState = WheelState::NONE;
    }
    return ret;
}

CursorPos InputSystem::GetMousePosition() { return m_CursorPos; }