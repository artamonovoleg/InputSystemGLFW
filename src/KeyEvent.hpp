//
// Created by artamonovoleg on 23.11.2020.
//

#pragma once
#include "Event.hpp"

class KeyEvent : public Event
{
    private:
        const int m_Key;
        PressState m_State;
    public:
        KeyEvent(int key, EventType t) : Event(EventCategory::KeyEvent), m_Key(key)
        {
            if (t == EventType::KeyPressedEvent)
                m_State = PressState::PRESSED;
            else
                m_State = PressState::RELEASED;
        };
        ~KeyEvent() = default;
        int GetKey() const { return m_Key; }
        PressState GetState() const { return m_State; }
};

class KeyPressedEvent : public KeyEvent
{
    private:
    public:
        explicit KeyPressedEvent(int key) : KeyEvent(key, EventType::KeyPressedEvent) {};
        ~KeyPressedEvent() = default;
};

class KeyReleasedEvent : public KeyEvent
{
    private:
    public:
        explicit KeyReleasedEvent(int key) : KeyEvent(key, EventType::KeyReleasedEvent) {};
        ~KeyReleasedEvent() = default;
};