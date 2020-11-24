//
// Created by artamonovoleg on 23.11.2020.
//

#pragma once
#include <map>
#include <functional>
#include "Event.hpp"
#include "InputHandler.hpp"

enum class CallbackType
{
    KeyCallback,
    ButtonCallback,
    ScrollCallback,
    CursorPosCallback,
    WindowResizeCallback,
    WindowCloseCallback
};

class EventSystem
{
    private:
        static std::map <int, std::function<void()>> m_Callbacks;
        static void PerformCallbacks(CallbackType type);
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
        static void AddCallback(CallbackType type, std::function<void()> fun);
        static void WindowCanClose(bool value);
        static bool IsWindowClose();
};
