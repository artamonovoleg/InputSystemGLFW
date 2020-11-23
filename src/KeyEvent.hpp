//
// Created by artamonovoleg on 23.11.2020.
//

#pragma once
#include "Event.hpp"

enum class KeyState
{
    NONE,
    PRESSED,
    HELD,
    RELEASED
};

class KeyEvent : public Event
{
    private:
        const int m_Key;
        KeyState m_State;
    public:
        KeyEvent(int key, EventType t) : Event(EventCategory::KeyEvent), m_Key(key)
        {
            if (t == EventType::KeyPressedEvent)
                m_State = KeyState::PRESSED;
            else
                m_State = KeyState::RELEASED;
        };

        int GetKey() const { return m_Key; }
        KeyState GetState() const { return m_State; }
};

class KeyPressedEvent : public KeyEvent
{
    private:
    public:
        KeyPressedEvent(int key) : KeyEvent(key, EventType::KeyPressedEvent) {};
};

class KeyReleasedEvent : public KeyEvent
{
    private:
    public:
        KeyReleasedEvent(int key) : KeyEvent(key, EventType::KeyReleasedEvent) {};
};