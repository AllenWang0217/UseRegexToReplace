#pragma once
#include "helper.h"
#include <string>
#include <fstream>
#include <regex>
#include <vector>
#include <algorithm>
using namespace std;
extern ofstream f_sub_session;
extern ofstream f_fake_based_flow;
extern ofstream f_initiaive_flow;
extern ofstream f_passive_flow;
namespace{
	bool isNotNeed(char a) { return a == ' ' || a == '"'; }
	vector<string> split(const string line, const string sep_symb) {
		vector<string> result;
		size_t pos = 0;
		size_t len = line.length();
		size_t symp_len = sep_symb.length();
		if (symp_len == 0) {
			result.push_back(line);
			return result;
		}
		while (pos < len) {
			int find_pos = line.find(sep_symb, pos);
			string substr;
			if (find_pos < 0) {
				substr = line.substr(pos, len - pos);
				substr.erase(remove_if(substr.begin(), substr.end(), isNotNeed), substr.end());
				result.push_back(substr);
				break;
			}
			substr = line.substr(pos, find_pos - pos);
			substr.erase(remove_if(substr.begin(), substr.end(), isNotNeed), substr.end());
			result.push_back(substr);
			pos = find_pos + symp_len;
		}
		return result;
	}	
	void handleWait(FlowResult* result, vector<string> imformation) {
		f_sub_session << imformation[0] << endl;
		f_fake_based_flow << "Wait " << result->msg << " (" << imformation[0] << "-" << imformation[1] << "-" << imformation[2] << ")" << endl;
	}
	void handleSend(FlowResult* result, vector<string> imformation) {
		f_fake_based_flow << "Send " << result->msg << " (" << imformation[0] << "-" << imformation[1] << "-" << imformation[2] << ")" << endl;
	}
}

struct AnalysisMsg {
	void analysis(FlowResult* result, string line) {
		vector<string> frist_split = split(line, ":");
		vector<string> second_split = split(frist_split[1], ",");
		if (result->isFakeSub) 
			handleWait(result, second_split);
		else
			handleSend(result, second_split);
	}
};