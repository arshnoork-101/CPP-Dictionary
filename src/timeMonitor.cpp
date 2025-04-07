#include <iostream>
#include "timeMonitor.h"

using namespace std;

namespace seneca
{
    void TimeMonitor::startEvent(const char* name)
    {
        m_eventName = name;

        m_startTime = std::chrono::steady_clock::now();

    }

    // stop the timer and return an event object with evnet name the duration
    Event TimeMonitor::stopEvent()
    {
        // calculate teh duration in nanoseconds
        Event event(m_eventName, chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now() - m_startTime));

        return event;
    }
}