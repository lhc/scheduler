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
			if (!processes.at(i)->execute())
				processes.erase(processes.begin()+i);
		}
	}
}
