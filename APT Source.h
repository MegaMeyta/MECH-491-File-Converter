//This file contains all classes and functions for APT Source translation functions.
//All classes and functions are within the namespace apt to prevent any conflicts from other header files.
//The definitions for everything can be found in "APT Source.cpp"

#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

namespace apt {

	//This is where all global variables are stored (i.e. origin, tool, feedrate)
	class workstation {

	};

	class tool {

	};

	class toolList {
		map<string, tool> dictionary;
	};

	//All the functions below have all the global variables from the main function and a vector made of all the atributes for the command (made in the main function)

	void CALSUB(FILE& output, vector<string> attributes);

	void COOLNT(FILE& output, vector<string> attributes);

	void CUTCOM(FILE& output, vector<string> attributes);

	void CYCLE(FILE& output, vector<string> attributes);

	void END(FILE& output, vector<string> attributes);

	void FEDRAT(FILE& output, vector<string> attributes);

	void LIMIT(FILE& output, vector<string> attributes);

	void LOADTL(FILE& output, vector<string> attributes);

	void MACHIN(FILE& output, vector<string> attributes);

	void MOVETO(FILE& output, vector<string> attributes);

	void MSYS(FILE& output, vector<string> attributes);

	void OFSTNO(FILE& output, vector<string> attributes);

	void OPNAME(FILE& output, vector<string> attributes);

	void OPTYPE(FILE& output, vector<string> attributes);

	void ORIGIN(FILE& output, vector<string> attributes);

	void PARTNO(FILE& output, vector<string> attributes);

	void PPRINT(FILE& output, vector<string> attributes);

	void RAPID(FILE& output, vector<string> attributes);

	void REWIND(FILE& output, vector<string> attributes);

	void SPINDL(FILE& output, vector<string> attributes);

	void STOP(FILE& output, vector<string> attributes);
	
	void TLNAME(FILE& output, vector<string> attributes);

	void TOOLNO(FILE& output, vector<string> attributes);

	void GOTO(FILE& output, vector<string> attributes);

	void MOVE(FILE& output, vector<string> attributes);

	void TOLER(FILE& output, vector<string> attributes);

	void INTOL(FILE& output, vector<string> attributes);

	void OUTTOL(FILE& output, vector<string> attributes);

	void CUTTER(FILE& output, vector<string> attributes);

	void MULTAX(FILE& output, vector<string> attributes);

	void UNITS(FILE& output, vector<string> attributes);

	void TLAXIS(FILE& output, vector<string> attributes);

	void FINI(FILE& output, vector<string> attributes);

	void CONTRL(FILE& output, vector<string> attributes);

	void SYN(FILE& output, vector<string> attributes);

	void MOVARC(FILE& output, vector<string> attributes);
}