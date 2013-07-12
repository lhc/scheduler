#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>

class Process;

class Scheduler
{
	public:
		static Scheduler *getInstance();
		void addProcess(Process *p);
		void run();

	private:
		static Scheduler *instance_;
		Scheduler() {}
		~Scheduler() {}
		std::vector<Process*> processes_;
};

#endif // SCHEDULER_H
