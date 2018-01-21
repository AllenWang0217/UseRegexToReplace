#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <regex>  
#include "helper.h"
#include "Handle.h"

extern ofstream fout;

struct HandleLeft : Handle{
	bool handleLeft(vector<string> fake, string line, regex pattern, FlowResult* result) {
		result->needFake = false;
		result->isFakeSub = false;
		smatch group;
		if (regex_search(line, group, pattern)) {
			string left = group[1];
			string right = group[2];
			auto it_left = find(fake.begin(), fake.end(), left);
			auto it_right = find(fake.begin(), fake.end(), right);
			if (it_left != fake.end() && it_right == fake.end())
			{
				string repl = "fake(" + left + ")";
				cout << regex_replace(line, pattern, repl + " -> $2 : $3") << endl;
				fout << regex_replace(line, pattern, repl + " -> $2 : $3") << endl;
				result->needFake = true;
				result->msg = group[3];
				return true;
			}
			if (it_right != fake.end() && it_left == fake.end())
			{
				string repl = "fake(" + right + ")";
				cout << regex_replace(line, pattern, "$1 -> " + repl + " : $3") << endl;
				fout << regex_replace(line, pattern, "$1 -> " + repl + " : $3") << endl;
				result->needFake = true;
				result->isFakeSub = true;
				result->msg = group[3];
				return true;
			}
		}
		return false;
	}
};
