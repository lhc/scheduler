#include "output.h"
#include <iostream>

bool Output::execute()
{
	init_proc();
	//the post-increment operator is slower than the pre-increment, don't use it unless you have a reason
	while (counter_ < 10)
	{
		std::cout << name_ << " is executing for the " << ++counter << " time" << std::endl;
		yield();
	}
	end_proc();
	return false;
}
