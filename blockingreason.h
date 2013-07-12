#ifndef BLOCKINGREASON_H
#define BLOCKINGREASON_H

#include "scheduler.h"
class Process;

class BlockingReason
{
	public:
		BlockingReason() { parent_ = Scheduler::getInstance()->getRunningProcess(); };
		virtual bool canWake() const = 0;
	private:
		Process *parent_;
};

#endif // BLOCKINGREASON_H
