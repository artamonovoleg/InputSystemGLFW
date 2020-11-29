//
// Created by user on 23.11.2020.
//

#pragma once
#include "KeyEvent.hpp"
#include "MouseEvent.hpp"

class InputSystem
{
    private:
        static PressState m_Keys[1024];
        static PressState m_Buttons[10];
        static WheelState m_WheelState;
        static CursorPos m_CursorPos;

        static bool IsPressed(int value, PressState* buffer);
        static bool IsReleased(int value, PressState* buffer);
        static bool IsDown(int value, PressState* buffer);

        static void OnKeyEvent(const Event& event);
        static void OnButtonEvent(const Event& event);
        static void OnScrollEvent(const Event& event);
        static void OnMouseMoveEvent(const Event& event);
    public:
        InputSystem() = delete;
        ~InputSystem() = delete;

        static void Init();
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