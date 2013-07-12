#ifndef SLEEPING_H
#define SLEEPING_H

#include "blockingreason.h"
#include <ctime>

class Sleeping : public BlockingReason
{
	public:
		Sleeping(int secs);
		virtual bool canWake() const;

	private:
		time_t timeToWake_;
};

#endif // SLEEPING_H
