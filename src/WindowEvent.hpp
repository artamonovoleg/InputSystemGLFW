//
// Created by artamonovoleg on 24.11.2020.
//

#pragma once
#include "Event.hpp"

class WindowResizeEvent : public Event
{
    private:
        const int m_Width, m_Height;
    public:
        WindowResizeEvent(int width, int height) : Event(EventCategory::WindowResizeEvent), m_Width(width), m_Height(height) {}
        int GetWidth() const { return m_Width; }
        int GetHeight() const { return m_Height; }
};

class WindowCloseEvent : public Event
{
    private:
    public:
        WindowCloseEvent() : Event(EventCategory::WindowCloseEvent) {}
};
