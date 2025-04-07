/*/////////////////////////////////////////////////////////////////////////
                          Workshop - 1
Full Name  : Arshnoor Kaur
Student ID#: 138345236
Email      : arshnoor-kaur@myseneca.ca
Section    : NJJ

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

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