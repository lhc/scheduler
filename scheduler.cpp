#include "scheduler.h"
#include "process.h"

Scheduler *Scheduler::instance = 0;

Scheduler *Scheduler::getInstance()
{
	if (!instance)
		instance = new Scheduler();
	return instance;
}

void Scheduler::addProcess(Process *p)
{
	processes.push_back(p);
}

void Scheduler::run()
{
	while (!processes.empty())
	{
		for (int i = 0; i < processes.size(); i++) {
			Process *proc = processes.at(i);
			switch(proc->deferredReason_)
			{
				case Process::Yielded:
					if (!proc->execute())
						processes.erase(processes.begin()+i);
					break;
				case Process::Sleeping:
					if (time(NULL) >= proc->timeToWake_)
						if (!proc->execute())
							processes.erase(processes.begin()+i);
					break;
			}
		}
	}
}
