#pragma once

#include "HandleRight.h"

struct HandleRightPattern2 : public Handle, public HandleRight {
	HandleRightPattern2(Handle* nextHandle) : nextHandle(nextHandle) {};
	bool exec(string line, vector<string> fake) {
		regex pattern(RIGHT_PATTERN_2);
		return handleRight(fake, this->nextHandle, line, pattern);
	}
private:
	Handle* nextHandle;
};