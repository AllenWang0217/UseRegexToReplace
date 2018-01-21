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

struct FlowResult {
	bool needFake = false;
	bool isFakeSub = false;
	std::string msg;
};

#define LEFT_PATTERN_1 "(.*) -> (.*) : (.*)"
#define LEFT_PATTERN_2 "(.*) --> (.*) : (.*)"
#define RIGHT_PATTERN_1 "(.*) <- (.*) : (.*)"
#define RIGHT_PATTERN_2 "(.*) <-- (.*) : (.*)"

#define ORIGINAL_DATA_PATH ".\\data\\originalData\\test.txt"
#define FAKE_OUT_DATE_PATH ".\\data\\producedData\\out.txt"
#define SUB_SESSION_DATE_PATH ".\\data\\producedData\\sub_session.txt"
#define FAKE_BASED_FLOW_DATE_PATH ".\\data\\producedData\\fake_based_flow.txt"
#define ASSERT_FAKE_OUT_DATE_PATH(fake) ".\\data\\assertedData\\" + fake +  "as_fake_out.txt"
#define ASSERT_SUB_SESSION_DATE_PATH(fake) ".\\data\\assertedData\\" + fake +  "as_fake_sub_session.txt"
#define ASSERT_FAKE_BASED_FLOW_DATE_PATH(fake) ".\\data\\assertedData\\" + fake +  "as_fake_based_flow.txt"
                                              