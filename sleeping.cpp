#include "sleeping.h"

Sleeping::Sleeping(int secs) :
	BlockingReason()
{
	timeToWake_ = time(NULL) + secs;
}

bool Sleeping::canWake() const
{
	return time(NULL) >= timeToWake_;
}
