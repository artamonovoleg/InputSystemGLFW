//
// Created by artamonovoleg on 23.11.2020.
//

#pragma once
#include "Event.hpp"
#include "InputHandler.hpp"

class EventSystem
{
    private:
        static bool m_WindowCanClose;

        static void HandleNewEvent(const Event& ev);

        static void OnKeyAction(int key, int action);
        static void OnButtonAction(int button, int action);
        static void OnWheelAction(double offset);
        static void OnCursorAction(double x, double y);
        static void OnWindowResizeAction(int width, int height);
        static void OnWindowCloseAction();
    public:
        static void Init();
        static void WindowCanClose(bool value);
        static bool IsWindowClose();
};
