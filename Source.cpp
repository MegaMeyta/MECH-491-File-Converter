#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "APT Source.h"

using namespace std;
using namespace apt;

string removeSpaces(string line);

vector<string> getAttributes(string line);

workstation station;
toolList workTools;

int main() {
	




	return 0;
}

vector<string> getAttributes(string line) {
	vector<string> attributes;
	string attribute;
	int start = 0;
	for (int i = 0; i < line.size(); i++) {
		if (line[i] == '/') {
			start = i + 1;
		}
		else if (line[i] == ',') {
			attribute = line.substr(start, i - start);
			attribute = removeSpaces(attribute);
			attributes.push_back(attribute);
			start = i + 1;
		}
		else if (i == line.size() - 1 ) {
			attribute = line.substr(start, i + 1 - start);
			attribute = removeSpaces(attribute);
			attributes.push_back(attribute);
		}
	}
	return attributes;
}

string removeSpaces(string line) {
	string result;
	for (int i = 0; i < line.size(); i++) {
		if (line[i] != ' ') {
			result.push_back(line[i]);
		}
	}
	return result;
}