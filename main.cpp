#include "output.h"

#include "output.h"
#include "scheduler.h"

int main()
{
	Output *out1 = new Output("First output");
	Output *out2 = new Output("Second output");

	Scheduler *sched = Scheduler::getInstance();
	sched->addProcess(out1);
	sched->addProcess(out2);
	sched->run();
}

