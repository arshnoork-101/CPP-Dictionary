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

#ifndef SENECA_TIMEMONITOR_H
#define SENECA_TIMEMONITOR_H
#include <chrono>
#include "event.h"

namespace seneca
{
	class TimeMonitor
	{
		std::chrono::steady_clock::time_point m_startTime;
		std::chrono::steady_clock::time_point m_endTime;
		const char* m_eventName{ nullptr };

	public:
		void startEvent(const char* name);
		Event stopEvent();
	};
}

#endif
