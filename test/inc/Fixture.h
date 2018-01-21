#pragma once
#include "gtest/gtest.h"
#include "../../code/inc/HandleLeftPattern1.h"
#include "../../code/inc/HandleLeftPattern2.h"
#include "../../code/inc/HandleRightPattern1.h"
#include "../../code/inc/HandleRightPattern2.h"
#include "../../code/inc/AnalysisMsg.h"
using namespace std;

namespace {
	bool isTwoFileEqual(string file_path1, string file_path2) {
		ifstream file;
		string str1, str2;
		file.open(file_path1);
		ASSERT_OPEN_SUCCESS(file);
		while (!file.eof())
			str1 += file.get();
		file.close();
		file.open(file_path2);
		ASSERT_OPEN_SUCCESS(file);
		while (!file.eof())
			str2 += file.get();
		file.close();
		if (str1 == str2)
			return true;
		else
			return false;
	}
}

class Fixture : public testing::Test {
public:
	void exec(vector<string> fake) {
		ifstream fin(ORIGINAL_DATA_PATH);
		ASSERT_OPEN_SUCCESS(fin)
		fout.close();
		f_sub_session.close();
		f_fake_based_flow.close();
		fout.open(FAKE_OUT_DATE_PATH);
		f_sub_session.open(SUB_SESSION_DATE_PATH);
		f_fake_based_flow.open(FAKE_BASED_FLOW_DATE_PATH);
		ASSERT_OPEN_SUCCESS(fin);
		char temp[1024] = { 0 };
		FlowResult* flowResult = new FlowResult();
		Handle* hr2 = new HandleRightPattern2(NULL);
		Handle* hr1 = new HandleRightPattern1(hr2);
		Handle* hl2 = new HandleLeftPattern2(hr1);
		Handle* hl1 = new HandleLeftPattern1(hl2);
		AnalysisMsg* analy = new AnalysisMsg();
		while (fin.getline(temp, sizeof(temp)))
		{
			string line = temp;
			if (flowResult->needFake) {
				cout << line << endl;
				fout << line << endl;
				flowResult->needFake = false;
				analy->analysis(flowResult, line);
				continue;
			}
			hl1->exec(line, fake, flowResult);
		}
		delete flowResult, hr1, hr2, hl1, hl2, analy;
		fin.clear();
		fin.close();
	}
	bool judge(vector<string> fake) { 
		string fake_ser;
		for(auto i : fake)
			fake_ser = fake_ser + i + "_";
		EXPECT_TRUE(isTwoFileEqual(FAKE_OUT_DATE_PATH, ASSERT_FAKE_OUT_DATE_PATH(fake_ser)));
		EXPECT_TRUE(isTwoFileEqual(SUB_SESSION_DATE_PATH, ASSERT_SUB_SESSION_DATE_PATH(fake_ser)));
		EXPECT_TRUE(isTwoFileEqual(FAKE_BASED_FLOW_DATE_PATH, ASSERT_FAKE_BASED_FLOW_DATE_PATH(fake_ser)));
		return true; 
	}
};	

