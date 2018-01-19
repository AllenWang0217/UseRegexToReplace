#pragma once

#include "HandleRight.h"

struct HandleRightPattern1 : public Handle, public HandleRight {
	HandleRightPattern1(Handle* nextHandle) : nextHandle(nextHandle) {};
	bool exec(string line, string fake) {
		regex pattern(RIGHT_PATTERN_1);
		return handleRight(fake, this->nextHandle, line, pattern);
	}
private:
	Handle* nextHandle;
};