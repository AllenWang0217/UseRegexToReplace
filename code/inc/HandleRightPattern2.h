#pragma once

#include "HandleRight.h"

struct HandleRightPattern2 : public Handle, public HandleRight {
	HandleRightPattern2(Handle* nextHandle) : nextHandle(nextHandle) {};
	void exec(string line, vector<string> fake, FlowResult* result) {
		regex pattern(RIGHT_PATTERN_2);
		if (!handleRight(fake, line, pattern, result)) {
			if (NULL != nextHandle)
				nextHandle->exec(line, fake, result);
		}
	}
private:
	Handle* nextHandle;
};