//
// Created by artamonovoleg on 23.11.2020.
//

#pragma once
#include "Event.hpp"
#include "InputHandler.hpp"

class EventSystem
{
    private:
        static void OnKeyAction(int key, int action);
        static void OnButtonAction(int button, int action);
        static void OnWheelAction(double offset);
    public:
        static void Init();
        static void HandleNewEvent(const Event& ev);

};
