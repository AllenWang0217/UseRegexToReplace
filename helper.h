#pragma once
#include <string>
#define ASSERT_OPEN_SUCCESS(fin)                   \
if (!fin)                                          \
{                                                  \
	cout << "fail to open the file" << endl;       \
}                                                  \
else                                               \
{                                                  \
/*	cout << "open the file successfully" << endl;*/\
}    

#define LEFT_PATTERN_1 "(.*) -> (.*) : (.*)"
#define LEFT_PATTERN_2 "(.*) --> (.*) : (.*)"
#define RIGHT_PATTERN_1 "(.*) <- (.*) : (.*)"
#define RIGHT_PATTERN_2 "(.*) <-- (.*) : (.*)"

struct FlowResult {
	bool needFake = false;
	bool isFakeSub = false;
	std::string msg;
};