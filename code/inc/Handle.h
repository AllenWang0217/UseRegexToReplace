#pragma once
#include <vector>
#include <string>
#include "helper.h"
using namespace std;

struct Handle {
	virtual void exec(string line, vector<string> fake, FlowResult* flowResult) = 0;
protected:
	Handle* nextHandle;
};