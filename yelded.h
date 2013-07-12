#ifndef YELDED_H
#define YELDED_H

#include "blockingreason.h"

class Yelded : public BlockingReason
{
	public:
		Yelded();
		virtual bool canWake() const;
};

#endif // YELDED_H
