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

#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H
#include <chrono>

namespace seneca {

	enum TimeUnits
	{
		Seconds = 2,
		Milliseconds = 5,
		Microseconds = 8,
		Nanoseconds = 11
	};

	class Event {

		std::string m_eventName{};
		std::chrono::nanoseconds m_duration{};

	public:
		Event();
		Event(const char* name, const std::chrono::nanoseconds& duration);
		friend std::ostream& operator << (std::ostream&, const Event&);
	};


}



#endif