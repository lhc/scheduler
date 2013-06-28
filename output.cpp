#include "output.h"
#include <iostream>

bool Output::execute()
{
	init_proc();
	//The post-increment operator is slower than the pre-increment, don't use it unless you have a reason
	/* Also using a for to increment the counter_ doesn't work, not entirely sure why but it seems
	 * the increment is not executed when we return to the function after the yield().
	 */
	while (counter_ < 10)
	{
		std::cout << name_ << " is executing for the " << ++counter_ << " time" << std::endl;
		if (sleep_)
			sleep(1);
		else
			yield();
	}
	end_proc();
	return false;
}
