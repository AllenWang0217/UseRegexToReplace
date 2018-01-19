#pragma once
#include <vector>
#include <string>
using namespace std;

struct Handle {
	virtual bool exec(string line, vector<string> fake) = 0;
protected:
	Handle* nextHandle;
};