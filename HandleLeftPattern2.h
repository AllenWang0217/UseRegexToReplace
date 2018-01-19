#pragma once

#pragma once

#include "HandleLeft.h"

struct HandleLeftPattern2 : public Handle, public HandleLeft {
	HandleLeftPattern2(Handle* nextHandle) : nextHandle(nextHandle) {};
	bool exec(string line, vector<string> fake) {
		regex pattern(LEFT_PATTERN_2);
		return handleLeft(fake, this->nextHandle, line, pattern);
	}
private:
	Handle* nextHandle;
};