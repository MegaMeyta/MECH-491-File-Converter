#include "APT Source.h"
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <iostream>

using namespace apt;

APTSource::APTSource(string inputFile) {
	this->input.open(inputFile);
	if (this->input.is_open()) {
		this->inputFileName = inputFile;
		this->input.close();
		cout << "file found";
	}
	else {
		cout << "File Does Not Exist";
	}


}

string APTSource::removeSpaces(string line) {
	string result;
	for (int i = 0; i < line.size(); i++) {
		if (line[i] != ' ') {
			result.push_back(line[i]);
		}
	}
	return result;
}\

vector<string> APTSource::getAttributes(string line) {
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
		else if (i == line.size() - 1) {
			attribute = line.substr(start, i + 1 - start);
			attribute = removeSpaces(attribute);
			attributes.push_back(attribute);
		}
	}
	return attributes;
}

void APTSource::convert() {
	input.open(inputFileName);
	int temp = inputFileName.find_last_of('.');
	outputFileName = inputFileName.substr(0, temp) + ".gcode";
	output.open(outputFileName);
	string line;
	string command;
	vector<string> attributes;
	while (getline(input, line)) {
		temp = line.find_first_of('/');
		command = removeSpaces(line.substr(0, temp));
		attributes = getAttributes(line);

		if (command == "CALSUB")
			CALSUB(attributes);
		if (command == "COOLNT")
			COOLNT(attributes);
		if (command == "CUTCOM")
			CUTCOM(attributes);
		if (command == "CYCLE")
			CYCLE(attributes);
		if (command == "END")
			END(attributes);
		if (command == "FEDRAT")
			FEDRAT(attributes);
		if (command == "LIMIT")
			LIMIT(attributes);
		if (command == "LOADTL")
			LOADTL(attributes);
		if (command == "MACHIN")
			MACHIN(attributes);
		if (command == "MOVETO")
			MOVETO(attributes);
		if (command == "MSYS")
			MSYS(attributes);
		if (command == "OFSTNO")
			OFSTNO(attributes);
		if (command == "OPNAME")
			OPNAME(attributes);
		if (command == "OPTYPE")
			OPTYPE(attributes);
		if (command == "ORIGIN")
			ORIGIN(attributes);
		if (command == "PARTNO")
			PARTNO(attributes);
		if (command == "PPRINT")
			PPRINT(attributes);
		if (command == "RAPID")
			RAPID(attributes);
		if (command == "SPINDL")
			SPINDL(attributes);
		if (command == "STOP")
			STOP(attributes);
		if (command == "TLNAME")
			TLNAME(attributes);
		if (command == "TOOLNO")
			TOOLNO(attributes);
		if (command == "GOTO")
			GOTO(attributes);
		if (command == "MOVE")
			MOVE(attributes);
		if (command == "TOLER")
			TOLER(attributes);
		if (command == "INTOL")
			INTOL(attributes);
		if (command == "OUTTOL")
			OUTTOL(attributes);
		if (command == "CUTTER")
			CUTTER(attributes);
		if (command == "MULTAX")
			MULTAX(attributes);
		if (command == "UNITS")
			UNITS(attributes);
		if (command == "TLAXIS")
			TLAXIS(attributes);
		if (command == "FINI")
			FINI(attributes);
		if (command == "CONTRL")
			CONTRL(attributes);
		if (command == "SYN")
			SYN(attributes);
		if (command == "MOVARC")
			MOVARC(attributes);
	}

	input.close();
	output.close();
}

void APTSource::CALSUB(vector<string> attributes) {
	if (attributes[3] == "CLDATA") {

	}

	if (attributes[3] == "SYSTEM") {

	}

	if (attributes[3] == "INCLUD") {

	}

}

void APTSource::COOLNT(vector<string> attributes) {

}

void APTSource::CUTCOM(vector<string> attributes) {
	if (attributes[2] == "ON") {
		if (attributes[3] == "LENGTH") {

		}
		if (attributes[3] == "XCOORD") {

		}
		if (attributes[3] == "YCOORD") {

		}
		if (attributes[3] == "ZCOORD") {

		}
		if (attributes[3] == "ADJUST") {

		}
	}
	if (attributes[2] == "OFF") {
		if (attributes[3] == "LENGTH") {

		}
		if (attributes[3] == "XCOORD") {

		}
		if (attributes[3] == "YCOORD") {

		}
		if (attributes[3] == "ZCOORD") {

		}
		if (attributes[3] == "ADJUST") {

		}
	}
	if (attributes[2] == "LEFT") {
		
	}
	if (attributes[2] == "RIGHT") {

	}
	if (attributes[2] == "CORNER") {

	}
	if (attributes[2] == "TRANSL") {

	}
	if (attributes[2] == "ROUND") {

	}
	if (attributes[2] == "NORMAL") {

	}
}

void APTSource::CYCLE(vector<string> attributes) {

}

void APTSource::END(vector<string> attributes) {

}

void APTSource::FEDRAT(vector<string> attributes) {

}

void APTSource::LIMIT(vector<string> attributes) {

}

void APTSource::LOADTL(vector<string> attributes) {

}

void APTSource::MACHIN(vector<string> attributes) {

}

void APTSource::MOVETO(vector<string> attributes) {

}

void APTSource::MSYS(vector<string> attributes) {

}

void APTSource::OFSTNO(vector<string> attributes) {

}

void APTSource::OPNAME(vector<string> attributes) {

}

void APTSource::OPTYPE(vector<string> attributes) {
	
}

void APTSource::ORIGIN(vector<string> attributes) {

}

void APTSource::PARTNO(vector<string> attributes) {

}

void APTSource::PPRINT(vector<string> attributes) {

}

void APTSource::RAPID(vector<string> attributes) {

}

void APTSource::REWIND(vector<string> attributes) {

}

void APTSource::SPINDL(vector<string> attributes) {

}

void APTSource::STOP(vector<string> attributes) {

}

void APTSource::TLNAME(vector<string> attributes) {

}

void APTSource::TOOLNO(vector<string> attributes) {

}

void APTSource::GOTO(vector<string> attributes) {

}

void APTSource::MOVE(vector<string> attributes) {

}

void APTSource::TOLER(vector<string> attributes) {

}

void APTSource::INTOL(vector<string> attributes) {

}

void APTSource::OUTTOL(vector<string> attributes) {

}

void APTSource::CUTTER(vector<string> attributes) {

}

void APTSource::MULTAX(vector<string> attributes) {

}

void APTSource::UNITS(vector<string> attributes) {

}

void APTSource::TLAXIS(vector<string> attributes) {

}

void APTSource::FINI(vector<string> attributes) {

}

void APTSource::CONTRL(vector<string> attributes) {

}

void APTSource::SYN(vector<string> attributes) {

}

void APTSource::MOVARC(vector<string> attributes) {

}