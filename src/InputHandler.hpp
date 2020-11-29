//
// Created by user on 23.11.2020.
//

#pragma once
#include "KeyEvent.hpp"
#include "MouseEvent.hpp"

class InputHandler
{
    private:

        PressState m_Keys[1024];
        PressState m_Buttons[10];
        WheelState m_WheelState;

        bool IsPressed(int value, PressState* buffer);
        bool IsReleased(int value, PressState* buffer);
        bool IsDown(int value, PressState* buffer);

        CursorPos m_CursorPos;

        // Only event system can call update methods
        void OnKeyEvent(const KeyEvent& event);
        void OnButtonEvent(const MouseButtonEvent& event);
        void OnScrollEvent(const MouseScrollEvent& event);
        void OnMouseMoveEvent(const MouseMoveEvent& event);
    public:
        InputHandler();
        ~InputHandler() = default;

        bool IsKeyPressed(int key);
        bool IsKeyDown(int key);
        bool IsKeyReleased(int key);

        bool IsButtonPressed(int button);
        bool IsButtonDown(int button);
        bool IsButtonReleased(int button);

        bool IsScrollingUp();
        bool IsScrollingDown();

        CursorPos GetMousePosition();
};