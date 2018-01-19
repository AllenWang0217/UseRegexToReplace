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

int main()
{
	ASSERT_OPEN_SUCCESS(fin);
	ASSERT_OPEN_SUCCESS(fout);
	char temp[1024] = { 0 };
	vector<string> fake;
	fake.push_back("BCD");
	fake.push_back("CDE");
	bool isfaked = false;
	while (fin.getline(temp, sizeof(temp)))
	{
		if (isfaked) {
			cout << temp << endl;
			fout << temp << endl;
			isfaked = false;
			continue;
		}
		string line = temp;
		Handle* hr2 = new HandleRightPattern2(NULL);
		Handle* hr1 = new HandleRightPattern1(hr2);
		Handle* hl2 =new HandleLeftPattern2(hr1);
		Handle* hl1 = new HandleLeftPattern1(hl2);
		isfaked = hl1->exec(line, fake);
		cout << isfaked << endl;
		//fout << line <<endl;
	}
	fin.clear();
	fin.close();
	fout.close();
	getchar();
	return 0;
}