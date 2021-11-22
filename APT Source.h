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

	void CALSUB(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void COOLNT(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void CUTCOM(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void CYCLE(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void END(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void FEDRAT(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void LIMIT(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void LOADTL(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void MACHIN(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void MOVETO(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void MSYS(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void OFSTNO(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void OPNAME(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void OPTYPE(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void ORIGIN(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void PARTNO(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void PPRINT(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void RAPID(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void REWIND(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void SPINDL(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void STOP(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);
	
	void TLNAME(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void TOOLNO(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void GOTO(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void MOVE(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void TOLER(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void INTOL(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void OUTTOL(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void CUTTER(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void MULTAX(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void UNITS(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void TLAXIS(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void FINI(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void CONTRL(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void SYN(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);

	void MOVARC(FILE& output, workstation& station, toolList& worktools, vector<string> attributes);
}