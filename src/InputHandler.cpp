//
// Created by user on 23.11.2020.
//

#include "InputHandler.hpp"

KeyState InputHandler::m_Keys[1024] = { KeyState::NONE };
ButtonState InputHandler::m_Buttons[10] = { ButtonState::NONE };
WheelState InputHandler::m_WheelState = WheelState::NONE;

void InputHandler::UpdateKeyState(int key, KeyState state)
{
    m_Keys[key] = state;
}

bool InputHandler::IsKeyPressed(int key)
{
    bool ret = false;
    if (m_Keys[key] == KeyState::PRESSED)
    {
        ret = true;
        m_Keys[key] = KeyState::HELD;
    }
    return ret;
}

bool InputHandler::IsKeyDown(int key)
{
    return (m_Keys[key] == KeyState::PRESSED || m_Keys[key] == KeyState::HELD);
}

bool InputHandler::IsKeyReleased(int key)
{
    bool ret = false;
    if (m_Keys[key] == KeyState::RELEASED)
    {
        ret = true;
        m_Keys[key] = KeyState::NONE;
    }
    return ret;
}

void InputHandler::UpdateButtonState(int button, ButtonState state)
{
    m_Buttons[button] = state;
}

bool InputHandler::IsButtonPressed(int button)
{
    bool ret = false;
    if (m_Buttons[button] == ButtonState::PRESSED)
    {
        ret = true;
        m_Buttons[button] = ButtonState::HELD;
    }
    return ret;
}

bool InputHandler::IsButtonDown(int button)
{
    return (m_Buttons[button] == ButtonState::PRESSED || m_Buttons[button] == ButtonState::HELD);
}

bool InputHandler::IsButtonReleased(int button)
{
    bool ret = false;
    if (m_Buttons[button] == ButtonState::RELEASED)
    {
        ret = true;
        m_Buttons[button] = ButtonState::NONE;
    }
    return ret;
}

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
