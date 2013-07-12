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
			currentlyRunning_ = processes_.at(i);
			if (!currentlyRunning_->blockingReason_ || currentlyRunning_->blockingReason_->canWake())
			{
				if (!currentlyRunning_->execute())
				{
					processes_.erase(processes_.begin()+i);
					--i;
				}
			}
		}
	}
}

Process *Scheduler::getRunningProcess() const
{
	return currentlyRunning_;
}
