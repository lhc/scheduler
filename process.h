#ifndef PROCESS_H
#define PROCESS_H

#include "scheduler.h"
#include <ctime>

#define init_proc() switch(state_) { case 0:
#define end_proc() }
#define yield() \
	do { \
		state_ == __LINE__; \
		deferredReason_ = Process::Yielded; \
		return true; \
		case __LINE__: ; \
	} while(0)
#define sleep(n) \
	do { \
		state_ == __LINE__; \
		deferredReason_ = Process::Sleeping; \
		timeToWake_ = time(NULL) + (n); \
		return true; \
		case __LINE__: ; \
	} while(0)

class Process
{
	public:
		Process() : state_(0), timeToWake_(0), deferredReason_(Yielded) {}

	protected:
		//Can't be private since derived classes will call yield which changes values
		int state_;
		unsigned int timeToWake_;
		enum {
			Yielded,
			Sleeping
		} deferredReason_;

	private:
		virtual bool execute() = 0;

	//This means the scheduler can access even protected or private members of the Process class
	friend Scheduler;
};

#endif // PROCESS_H
