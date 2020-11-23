//
// Created by artamonovoleg on 23.11.2020.
//

#pragma once

// base class Event use only this. No reasons for different more
enum class EventCategory
{
    None,
    KeyEvent,
    MouseEvent
};

enum class EventType
{
    None,
    KeyPressedEvent, KeyReleasedEvent
};

class Event
{
    private:
    public:
        Event(EventCategory t) : category(t) {};
        ~Event() = default;
        const EventCategory category = EventCategory::None;
};