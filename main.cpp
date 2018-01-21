#include "test/inc/test.h"

ofstream fout(FAKE_OUT_DATE_PATH);
ofstream f_sub_session(SUB_SESSION_DATE_PATH);
ofstream f_fake_based_flow(FAKE_BASED_FLOW_DATE_PATH);

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	fout.close();
	f_sub_session.close();
	f_fake_based_flow.close();
	getchar();
}