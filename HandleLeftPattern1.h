#pragma once

#include "HandleLeft.h"

struct HandleLeftPattern1 : public Handle, public HandleLeft {
	HandleLeftPattern1(Handle* nextHandle) : nextHandle(nextHandle) {};
	bool exec(string line, vector<string> fake) {
		regex pattern(LEFT_PATTERN_1);
		return handleLeft(fake, this->nextHandle, line, pattern);
	}
private:
	Handle* nextHandle;
};