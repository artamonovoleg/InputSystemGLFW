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

        friend class EventSystem;

        static PressState m_Keys[1024];
        static PressState m_Buttons[10];
        static WheelState m_WheelState;

        static bool IsPressed(int value, PressState* buffer);
        static bool IsReleased(int value, PressState* buffer);
        static bool IsDown(int value, PressState* buffer);

        static CursorPos m_CursorPos;

        // Only event system can call update methods
        static void UpdateKeyState(int key, PressState state);
        static void UpdateButtonState(int button, PressState state);
        static void UpdateWheelState(WheelState state);
        static void UpdateCursorPosition(CursorPos pos);
    public:
        static bool IsKeyPressed(int key);
        static bool IsKeyDown(int key);
        static bool IsKeyReleased(int key);

        static bool IsButtonPressed(int button);
        static bool IsButtonDown(int button);
        static bool IsButtonReleased(int button);

        static bool IsScrollingUp();
        static bool IsScrollingDown();

        static CursorPos GetMousePosition();
};