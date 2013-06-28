#ifndef OUTPUT_H
#define OUTPUT_H

#include <string>
#include "process.h"

class Output : public Process
{
	public:
		Output(std::string name, bool sleep = false) : name_(name), counter_(0), sleep_(sleep) {}

	protected:
		virtual bool execute();

	private:
		std::string name_;
		int counter_;
		bool sleep_;
};

#endif // OUTPUT_H
