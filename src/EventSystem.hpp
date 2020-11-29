//
// Created by artamonovoleg on 23.11.2020.
//

#pragma once
#include <unordered_map>
#include <list>
#include <functional>
#include "Event.hpp"
#include "InputHandler.hpp"

class EventSystem
{
    private:
        static std::unordered_map<EventCategory, std::list<std::function<void(const Event&)>>> listeners;
        static bool m_WindowCanClose;

        static void SendEvent(const Event& ev);

        static void OnKeyAction(int key, int action);
        static void OnButtonAction(int button, int action);
        static void OnWheelAction(double offset);
        static void OnCursorAction(double x, double y);
        static void OnWindowResizeAction(int width, int height);
        static void OnWindowCloseAction();
    public:
        static void Init();
        static void AddListener(EventCategory eventId, std::function<void(const Event&)> const& listener)
        {
            listeners[eventId].push_back(listener);
        }

        static void WindowCanClose(bool value);
        static bool IsWindowClose();
};
