#include "HandleLeftPattern1.h"
#include "HandleLeftPattern2.h"
#include "HandleRightPattern1.h"
#include "HandleRightPattern2.h"
#include "AnalysisMsg.h"
#include "test.h"

using namespace std;

ifstream fin("test.txt");
ofstream fout("out.txt");
ofstream f_sub_session("sub_session.txt");
ofstream f_fake_based_flow("fake_based_flow.txt");
vector<string> fake;

int main(int argc, char **argv)
{
	ASSERT_OPEN_SUCCESS(fin);
	ASSERT_OPEN_SUCCESS(fout);
	char temp[1024] = { 0 };
	fake.push_back("BCD");
	fake.push_back("CDE");
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
	fout.close();
	f_sub_session.close();
	f_fake_based_flow.close();
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}