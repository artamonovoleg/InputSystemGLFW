//
// Created by artamonovoleg on 23.11.2020.
//

#pragma once

#include "Event.hpp"

enum class ButtonState
{
    NONE,
    PRESSED,
    HELD,
    RELEASED
};

enum class WheelState
{
    NONE,
    SCROLL_UP,
    SCROLL_DOWN
};

class MouseScrollEvent : public Event
{
    private:
        const WheelState m_State;
    public:
        MouseScrollEvent(WheelState state)
            : Event(EventCategory::MouseWheelEvent), m_State(state) {}

        WheelState GetState() const { return m_State; }
};

class MouseButtonEvent : public Event
{
    private:
        const int m_Button;
        ButtonState m_State;
    public:
        MouseButtonEvent(int button, EventType t)
            : Event(EventCategory::MouseButtonEvent), m_Button(button)
        {
            if (t == EventType::MousePressedEvent)
                m_State = ButtonState::PRESSED;
            else
                m_State = ButtonState::RELEASED;
        }

        int GetButton() const { return m_Button; }
        ButtonState GetState() const { return m_State; }
};

class MousePressedEvent : public MouseButtonEvent
{
    private:
    public:
        MousePressedEvent(int button)
            : MouseButtonEvent(button, EventType::MousePressedEvent){}
};

class MouseReleasedEvent : public MouseButtonEvent
{
    private:
    public:
        MouseReleasedEvent(int button)
            : MouseButtonEvent(button, EventType::MouseReleasedEvent) {}
};

