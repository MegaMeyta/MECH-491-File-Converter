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

	class tool {
	public:

		string tool_type;
		double tool_diameter;
		double tool_upper_radius;
		double tool_lower_radius;
		double tool_length;
		double tool_taper_angle;
		double tool_tip_angle;
		double tool_x_center_r1;
		double tool_y_center_r1;
		double tool_x_center_r2;
		double tool_y_center_r2;

		tool(vector<string> attributes);
	};

	//This is where all global variables are stored (i.e. origin, tool, feedrate)
	class workstation {
	public: 
		bool rapid;
		string unit;
		double feedrate;
		vector<tool> tool_catalogue;
		vector<string> tool_list;

		int tool_n;
		bool new_tool;

		//Current position of tool
		double current_x;
		double current_y;
		double current_z;
		double current_i;
		double current_j;
		double current_k;

		//tool path circle parameters
		bool arc;
		double arc_x;
		double arc_y;
		double arc_z;
		double arc_i;
		double arc_j;
		double arc_k;
		double arc_r;
		double arc_t;
		double arc_f;
		double arc_d;
		double arc_e;

		//Absolute Coordinate System
		double  absolute[3][3];

		workstation();
	};

	//Main Class that contains all variables and functions related to converting the APTSource File
	class APTSource {
	public:
		workstation station;
		string inputFileName;
		string outputFileName;
		ifstream input;
		ofstream output;
		int line_n;
		int gcode_n;

		APTSource(string inputFile);

		string removeSpaces(string line);

		vector<string> getAttributes(string line);

		void TOOL_PATH(vector<string> attributes);
		void TLDATA(vector<string> attributes);
		void FEDRAT(vector<string> attributes);
		void RAPID();
		void CYCLE(vector<string> attributes);
		void GOTO(vector<string> attributes);
		void GODTLA(vector<string> attributes);
		void CIRCLE(vector<string> attributes);
		void MSYS(vector<string> attributes);
		void END_OF_PATH();


		void convert();

		//void counter();
	};
}