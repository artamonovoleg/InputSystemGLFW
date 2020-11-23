//
// Created by user on 23.11.2020.
//

#pragma once
#include "Event.hpp"
#include "InputHandler.hpp"

class EventSystem
{
    private:
    public:
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