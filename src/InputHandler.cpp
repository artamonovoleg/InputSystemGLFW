//
// Created by artamonovoleg on 23.11.2020.
//

#include "InputHandler.hpp"

PressState InputHandler::m_Keys[1024] = { PressState::NONE };
PressState InputHandler::m_Buttons[10] = { PressState::NONE };
WheelState InputHandler::m_WheelState = WheelState::NONE;
CursorPos InputHandler::m_CursorPos = { 0, 0 };

// Universal methods to check states of keys or buttons
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

// Keyboard
void InputHandler::UpdateKeyState(int key, PressState state) { m_Keys[key] = state; }
bool InputHandler::IsKeyPressed(int key) { return IsPressed(key, m_Keys); }
bool InputHandler::IsKeyDown(int key) { return IsDown(key, m_Keys); }
bool InputHandler::IsKeyReleased(int key) { return IsReleased(key, m_Keys); }

// Mouse buttons
void InputHandler::UpdateButtonState(int button, PressState state) { m_Buttons[button] = state; }
bool InputHandler::IsButtonPressed(int button) { return IsPressed(button, m_Buttons); }
bool InputHandler::IsButtonDown(int button) { return IsDown(button, m_Buttons); }
bool InputHandler::IsButtonReleased(int button) { return IsReleased(button, m_Buttons); }

// Wheel scrolling
void InputHandler::UpdateWheelState(WheelState state)
{
    m_WheelState = state;
}

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

// Cursor
void InputHandler::UpdateCursorPosition(CursorPos pos) { m_CursorPos = pos; }
CursorPos InputHandler::GetMousePosition() { return m_CursorPos; }





