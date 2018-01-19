#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <regex>  
#include "Handle.h"
#include "helper.h"

extern ofstream fout;

struct HandleLeft {
	bool handleLeft(vector<string> fake, Handle* nextHandle, string line, regex pattern) {
		smatch group;
		if (regex_search(line, group, pattern)) {
			string left = group[1];
			string right = group[2];
			cout << "left is : " << left << endl;
			cout << "right is : " << right << endl;
			auto it_left = find(fake.begin(), fake.end(), left);
			auto it_right = find(fake.begin(), fake.end(), right);
			if (it_left != fake.end() && it_right == fake.end())
			{
				string repl = "fake(" + left + ")";
				cout << regex_replace(line, pattern, repl + " -> $2 : $3") << endl;
				fout << regex_replace(line, pattern, repl + " -> $2 : $3") << endl;
				return true;
			}
			if (it_right != fake.end() && it_left == fake.end())
			{
				string repl = "fake(" + right + ")";
				cout << regex_replace(line, pattern, "$1 -> " + repl + " : $3") << endl;
				fout << regex_replace(line, pattern, "$1 -> " + repl + " : $3") << endl;
				return true;
			}
			return false;
		}
		else
			if (NULL != nextHandle)
				return nextHandle->exec(line, fake);
			else
				return false;
	}
};