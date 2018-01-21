#pragma once
#include "Fixture.h"

TEST_F(Fixture, BCD_as_fake) {
	vector<string> fake;
	fake.push_back("BCD");
	exec(fake);
	fout.clear();
	EXPECT_TRUE(judge(fake));
}

TEST_F(Fixture, CDE_as_fake) {
	vector<string> fake;
	fake.push_back("CDE");
	exec(fake);
	EXPECT_TRUE(judge(fake));
}

TEST_F(Fixture, BCD_and_CDE_as_fake) {
	vector<string> fake;
	fake.push_back("BCD");
	fake.push_back("CDE");
	exec(fake);
	EXPECT_TRUE(judge(fake));
}