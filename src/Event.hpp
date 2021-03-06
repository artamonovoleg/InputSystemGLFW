//
// Created by artamonovoleg on 23.11.2020.
//

#pragma once

// base class Event use only this. No reasons for different more
enum class EventCategory
{
    None,
    KeyEvent,
    MouseButtonEvent, MouseWheelEvent, MouseMoveEvent,
    WindowResizeEvent, WindowCloseEvent
};

enum class EventType
{
    None,
    KeyPressedEvent, KeyReleasedEvent,
    MousePressedEvent, MouseReleasedEvent
};

enum class PressState
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

class Event
{
    private:
    public:
        explicit Event(EventCategory t) : category(t) {};
        virtual ~Event() = default;
        const EventCategory category = EventCategory::None;
};