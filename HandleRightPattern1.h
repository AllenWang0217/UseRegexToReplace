#pragma once

#include "HandleRight.h"

struct HandleRightPattern1 : public Handle, public HandleRight {
	HandleRightPattern1(Handle* nextHandle) : nextHandle(nextHandle) {};
	void exec(string line, vector<string> fake, FlowResult* result) {
		regex pattern(RIGHT_PATTERN_1);
		if (!handleRight(fake, line, pattern, result)) {
			if (NULL != nextHandle)
				nextHandle->exec(line, fake, result);
		}
	}
private:
	Handle* nextHandle;
};