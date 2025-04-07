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

#ifndef SENECA_LOGGER_H
#define SENECA_LOGGER_H
#include "event.h"

namespace seneca {

	class Logger {

		Event* m_events{ nullptr };
		size_t m_size{ 0 };

	public:
		Logger();

		Logger(const Logger& src) = delete;
		Logger& operator=(const Logger& src) = delete;

		Logger(Logger&& src) noexcept;
		Logger& operator=(Logger&& src) noexcept;

		~Logger();

		void addEvent(const Event& event);
		std::ostream& display(std::ostream& os) const;

	};

	std::ostream& operator << (std::ostream& os, const Logger& ro);


}


#endif