#pragma once

#include "HandleLeft.h"

struct HandleLeftPattern1 : public Handle, public HandleLeft {
	HandleLeftPattern1(Handle* nextHandle) : nextHandle(nextHandle) {};
	void exec(string line, vector<string> fake, FlowResult* result) {
		regex pattern(LEFT_PATTERN_1);
		if (!handleLeft(fake, line, pattern, result)) {
			if (NULL != nextHandle)
				nextHandle->exec(line, fake, result);
		}
	}
private:
	Handle* nextHandle;
};