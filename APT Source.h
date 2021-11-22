//This ifstream contains all classes and functions for APT Source translation functions.
//All classes and functions are within the namespace apt to prevent any conflicts from other header ifstreams.
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

	//Main Class that contains all variables and functions related to converting the APTSource File
	class APTSource {
	public:
		workstation station;
		toolList toollist;
		string inputFileName;
		string outputFileName;
		ifstream input;
		ofstream output;

		APTSource(string inputFile);

		string removeSpaces(string line);

		vector<string> getAttributes(string line);

		void CALSUB(vector<string> attributes);

		void COOLNT(vector<string> attributes);

		void CUTCOM(vector<string> attributes);

		void CYCLE(vector<string> attributes);

		void END(vector<string> attributes);

		void FEDRAT(vector<string> attributes);

		void LIMIT(vector<string> attributes);

		void LOADTL(vector<string> attributes);

		void MACHIN(vector<string> attributes);

		void MOVETO(vector<string> attributes);

		void MSYS(vector<string> attributes);

		void OFSTNO(vector<string> attributes);

		void OPNAME(vector<string> attributes);

		void OPTYPE(vector<string> attributes);

		void ORIGIN(vector<string> attributes);

		void PARTNO(vector<string> attributes);

		void PPRINT(vector<string> attributes);

		void RAPID(vector<string> attributes);

		void REWIND(vector<string> attributes);

		void SPINDL(vector<string> attributes);

		void STOP(vector<string> attributes);

		void TLNAME(vector<string> attributes);

		void TOOLNO(vector<string> attributes);

		void GOTO(vector<string> attributes);

		void MOVE(vector<string> attributes);

		void TOLER(vector<string> attributes);

		void INTOL(vector<string> attributes);

		void OUTTOL(vector<string> attributes);

		void CUTTER(vector<string> attributes);

		void MULTAX(vector<string> attributes);

		void UNITS(vector<string> attributes);

		void TLAXIS(vector<string> attributes);

		void FINI(vector<string> attributes);

		void CONTRL(vector<string> attributes);

		void SYN(vector<string> attributes);

		void MOVARC(vector<string> attributes);

		void convert();
	};
}