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

        static PressState m_Keys[1024];
        static PressState m_Buttons[10];
        static WheelState m_WheelState;

        static bool IsPressed(int value, PressState* buffer);
        static bool IsReleased(int value, PressState* buffer);
        static bool IsDown(int value, PressState* buffer);
    public:
        static void UpdateKeyState(int key, PressState state);
        static bool IsKeyPressed(int key);
        static bool IsKeyDown(int key);
        static bool IsKeyReleased(int key);

        static void UpdateButtonState(int button, PressState state);
        static bool IsButtonPressed(int button);
        static bool IsButtonDown(int button);
        static bool IsButtonReleased(int button);

        static void UpdateWheelState(WheelState state);
        static bool IsScrollingUp();
        static bool IsScrollingDown();
};