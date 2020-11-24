//
// Created by artamonovoleg on 23.11.2020.
//

#pragma once

#include "Event.hpp"



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

struct CursorPos
{
    double x, y;
};

class MouseMoveEvent : public Event
{
    private:
        const CursorPos m_CursorPos;
    public:
        explicit MouseMoveEvent(CursorPos pos)
            : Event(EventCategory::MouseMoveEvent), m_CursorPos(pos) {}
        ~MouseMoveEvent() override = default;
        CursorPos GetPos() const { return m_CursorPos; }
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

