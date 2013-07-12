#ifndef PROCESS_H
#define PROCESS_H

#include "scheduler.h"
#include "blockingreason.h"
#include "yelded.h"
#include "sleeping.h"
#include <ctime>

#define init_proc() switch(state_) { case 0:
#define end_proc() }
#define yield() \
	do { \
		state_ == __LINE__; \
		blockingReason_ = new Yelded(); \
		return true; \
		case __LINE__: ; \
	} while(0)
#define sleep(n) \
	do { \
		state_ == __LINE__; \
		blockingReason_ = new Sleeping((n)); \
		return true; \
		case __LINE__: ; \
	} while(0)

class Process
{
	public:
		Process() : state_(0), blockingReason_(NULL) {}

	protected:
		//Can't be private since derived classes will call yield which changes values
		int state_;
		BlockingReason *blockingReason_;

	private:
		virtual bool execute() = 0;
		BlockingReason *blockingReason() const;

	//This means the scheduler can access even protected or private members of the Process class
	friend Scheduler;
};

#endif // PROCESS_H
