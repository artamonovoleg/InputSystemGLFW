//
// Created by user on 23.11.2020.
//

#pragma once
#include "KeyEvent.hpp"

class InputHandler
{
    private:
        InputHandler() = default;
        ~InputHandler() = default;

        static KeyState m_Keys[1024];
    public:
        static void UpdateKeyState(int key, KeyState state)
        {
            m_Keys[key] = state;
        }

        static bool IsKeyPressed(int key)
        {
            bool ret = false;
            if (m_Keys[key] == KeyState::PRESSED)
            {
                ret = true;
                m_Keys[key] = KeyState::HELD;
            }

            return ret;
        }

        static bool IsKeyDown(int key)
        {
            return (m_Keys[key] == KeyState::PRESSED || m_Keys[key] == KeyState::HELD);
        }

        static bool IsKeyReleased(int key)
        {
            bool ret = false;
            if (m_Keys[key] == KeyState::RELEASED)
            {
                ret = true;
                m_Keys[key] = KeyState::NONE;
            }

            return ret;
        }
};