#pragma once
#include <string>
using namespace std;

struct Handle {
	virtual bool exec(string line, string fake) = 0;
protected:
	Handle* nextHandle;
};