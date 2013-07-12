#include "yelded.h"

Yelded::Yelded() :
	BlockingReason()
{
}

bool Yelded::canWake() const
{
	return true;
}
