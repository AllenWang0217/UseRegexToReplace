#include <iostream>
#include <sstream>
#include <fstream>
#include <string> 
#include <vector>
#include <regex>  
#include "helper.h"
#include "HandleLeftPattern1.h"
#include "HandleLeftPattern2.h"
#include "HandleRightPattern1.h"
#include "HandleRightPattern2.h"
using namespace std;

ifstream fin("test.txt");
ofstream fout("out.txt");
ofstream f_sub_session("sub_session.txt");
ofstream f_initiaive_flow("initiaive_flow.txt");
ofstream f_passive_flow("passive_flow.txt");

int main()
{
	ASSERT_OPEN_SUCCESS(fin);
	ASSERT_OPEN_SUCCESS(fout);
	char temp[1024] = { 0 };
	vector<string> fake;
	fake.push_back("BCD");
	fake.push_back("CDE");
	FlowResult* flowResult = new FlowResult();
	Handle* hr2 = new HandleRightPattern2(NULL);
	Handle* hr1 = new HandleRightPattern1(hr2);
	Handle* hl2 = new HandleLeftPattern2(hr1);
	Handle* hl1 = new HandleLeftPattern1(hl2);
	while (fin.getline(temp, sizeof(temp)))
	{
		if (flowResult->needFake) {
			cout << temp << endl;
			fout << temp << endl;
			flowResult->needFake = false;
			continue;
		}
		string line = temp;
		hl1->exec(line, fake, flowResult);
	}
	delete flowResult, hr1, hr2, hl1, hl2;
	fin.clear();
	fin.close();
	fout.close();
	getchar();
	return 0;
}