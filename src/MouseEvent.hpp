//
// Created by artamonovoleg on 23.11.2020.
//

#pragma once

#include "Event.hpp"

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
        explicit MouseScrollEvent(WheelState state)
            : Event(EventCategory::MouseWheelEvent), m_State(state) {}
        ~MouseScrollEvent() override = default;
        WheelState GetState() const { return m_State; }
};

class MouseButtonEvent : public Event
{
    private:
        const int m_Button;
        PressState m_State;
    public:
        MouseButtonEvent(int button, EventType t)
            : Event(EventCategory::MouseButtonEvent), m_Button(button)
        {
            if (t == EventType::MousePressedEvent)
                m_State = PressState::PRESSED;
            else
                m_State = PressState::RELEASED;
        }
        ~MouseButtonEvent() override = default;
        int GetButton() const { return m_Button; }
        PressState GetState() const { return m_State; }
};

class MousePressedEvent : public MouseButtonEvent
{
    private:
    public:
        explicit MousePressedEvent(int button)
            : MouseButtonEvent(button, EventType::MousePressedEvent){}
        ~MousePressedEvent() override = default;
};

class MouseReleasedEvent : public MouseButtonEvent
{
    private:
    public:
        explicit MouseReleasedEvent(int button)
            : MouseButtonEvent(button, EventType::MouseReleasedEvent) {}
        ~MouseReleasedEvent() override = default;
};

