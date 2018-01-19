#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <regex>  
#include "Handle.h"
#include "helper.h"

extern ofstream fout;

struct HandleRight {
	bool handleRight(string fake, Handle* nextHandle, string line, regex pattern) {
		smatch group;
		if (regex_search(line, group, pattern)) {
			string left = group[1];
			cout << "left is : " << left << endl;
			if (fake == left) {
				string repl = "fake(" + left + ")";
				cout << regex_replace(line, pattern, repl + " <- $2 : $3") << endl;
				fout << regex_replace(line, pattern, repl + " <- $2 : $3") << endl;
				return true;
			}
			string right = group[2];
			cout << "right is : " << right << endl;
			if (fake == right) {
				string repl = "fake(" + right + ")";
				cout << regex_replace(line, pattern, "$1 <- " + repl + " : $3") << endl;
				fout << regex_replace(line, pattern, "$1 <- " + repl + " : $3") << endl;
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