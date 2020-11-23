//
// Created by user on 23.11.2020.
//

#pragma once
#include "KeyEvent.hpp"
#include "MouseEvent.hpp"

class InputHandler
{
    private:
        InputHandler() = default;
        ~InputHandler() = default;

        static KeyState m_Keys[1024];
        static ButtonState m_Buttons[10];
        static WheelState m_WheelState;
    public:
        static void UpdateKeyState(int key, KeyState state);
        static bool IsKeyPressed(int key);
        static bool IsKeyDown(int key);
        static bool IsKeyReleased(int key);

        static void UpdateButtonState(int button, ButtonState state);
        static bool IsButtonPressed(int button);
        static bool IsButtonDown(int button);
        static bool IsButtonReleased(int button);

        static void UpdateWheelState(WheelState state);
        static bool IsScrollingUp();
        static bool IsScrollingDown();
};