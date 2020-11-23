//
// Created by user on 23.11.2020.
//

#pragma once
#include "Event.hpp"
#include "InputHandler.hpp"

enum class WindowManager
{
    GLFW_WM
};

class EventSystem
{
    private:
        static void KeyBoardFun(int key, int action);
    public:
        static void Init(void* window, WindowManager wm);
        template <typename T>
        static void HandleNewEvent(const T& ev)
        {
            // do some stuff
            switch (ev.category)
            {
                case EventCategory::KeyEvent:
                    InputHandler::UpdateKeyState(ev.GetKey(), ev.GetState());
                    break;
                case EventCategory::MouseEvent:
                    break;
                case EventCategory::None:
                    break;
            }
        }
};
