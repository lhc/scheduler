#include "scheduler.h"
#include "process.h"

Scheduler *Scheduler::instance_ = 0;

Scheduler *Scheduler::getInstance()
{
	if (!instance_)
		instance_ = new Scheduler();
	return instance_;
}

void Scheduler::addProcess(Process *p)
{
	processes_.push_back(p);
}

void Scheduler::run()
{
	while (!processes_.empty())
	{
		for (int i = 0; i < processes_.size(); i++) {
			Process *proc = processes_.at(i);
			switch(proc->deferredReason_)
			{
				case Process::Yielded:
					if (!proc->execute())
					{
						processes_.erase(processes_.begin()+i);
						--i;
					}
					break;
				case Process::Sleeping:
					if (time(NULL) >= proc->timeToWake_)
						if (!proc->execute())
						{
							processes_.erase(processes_.begin()+i);
							--i;
						}
					break;
			}
		}
	}
}
