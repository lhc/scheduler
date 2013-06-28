#ifndef OUTPUT_H
#define OUTPUT_H

#include <string>
#include "process.h"

class Output : public Process
{
	public:
		Output(std::string name) : name_(name), counter(0) {}

	protected:
		virtual bool execute();

	private:
		std::string name_;
		int counter_;
};

#endif // OUTPUT_H
