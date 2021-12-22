#include "APT Source.h"
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <iostream>

using namespace apt;

tool::tool(vector<string> attributes) {
	if (attributes[0] == "MILL") {
		if (attributes.size() == 6) {
			tool_type = attributes[0];
			tool_diameter = stod(attributes[1]);
			tool_lower_radius = stod(attributes[2]);
			tool_length = stod(attributes[3]);
			tool_taper_angle = stod(attributes[4]);
			tool_tip_angle = stod(attributes[5]);
		}

		if (attributes.size() == 8) {
			tool_type = attributes[0];
			tool_diameter = stod(attributes[1]);
			tool_lower_radius = stod(attributes[2]);
			tool_length = stod(attributes[3]);
			tool_taper_angle = stod(attributes[4]);
			tool_tip_angle = stod(attributes[5]);
			tool_x_center_r1 = stod(attributes[6]);
			tool_y_center_r1 = stod(attributes[7]);
		}

		if (attributes.size() == 10) {
			tool_type = attributes[0];
			tool_diameter = stod(attributes[1]);
			tool_lower_radius = stod(attributes[2]);
			tool_length = stod(attributes[3]);
			tool_taper_angle = stod(attributes[4]);
			tool_tip_angle = stod(attributes[5]);
			tool_x_center_r1 = stod(attributes[6]);
			tool_y_center_r1 = stod(attributes[7]);
			tool_x_center_r2 = stod(attributes[8]);
			tool_y_center_r2 = stod(attributes[9]);
		}
	}
}

workstation::workstation() {
	rapid = false;
	for (int i = 0; i < 3; i++) {
		for (int a = 0; a < 3; a++) {
			absolute[i][a] = 0;
		}
	}
	feedrate = 0;
	unit = "metric";
	current_x = 0;
	current_y = 0;
	current_z = 0;
	current_i = 0;
	current_j = 0;
	current_k = 1;

	arc = false;
	arc_x = 0;
	arc_y = 0;
	arc_z = 0;
	arc_i = 0;
	arc_j = 0;
	arc_k = 0;
	arc_r = 0;
	arc_t = 0;
	arc_f = 0;
	arc_d = 0;
	arc_e = 0;
	
	tool_n = 0;
	new_tool = false;
}

APTSource::APTSource(string inputFile) {
	gcode_n = 0;
	line_n = 0;
	this->input.open(inputFile);
	if (this->input.is_open()) {
		this->inputFileName = inputFile;
		this->input.close();
		std::cout << "file found";
	}
	else {
		std::cout << "File Does Not Exist";
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
	line_n = 0;
	gcode_n = 0;
	input.open(inputFileName);
	int temp = inputFileName.find_last_of('.');
	outputFileName = inputFileName.substr(0, temp) + ".gcode";
	output.open(outputFileName);
	string line;
	string command;
	vector<string> attributes;
	output << "N" << gcode_n << " " << "G17 ";
	int unit; 
	std::cout << "Type of Units (1 for Metric, 2 for Imperial): ";
	std::cin >> unit;
	if (unit == 1) {
		output << "G21 ";
	}
	else if (unit == 2) {
		output << "G20 ";
	}

	output << "G94 G90\n\n";
	gcode_n++;

	while (getline(input, line)) {
		line_n++;
		temp = line.find_first_of('/');
		command = removeSpaces(line.substr(0, temp));
		attributes = getAttributes(line);

		/*if (command == "CALSUB")
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
			MOVARC(attributes);*/

		if (command == "TOOLPATH")
			TOOL_PATH(attributes);
		if (command == "TLDATA")
			TLDATA(attributes);
		if (command == "FEDRAT")
			FEDRAT(attributes);
		if (command == "RAPID")
			RAPID();
		if (command == "CYCLE")
			CYCLE(attributes);
		if (command == "GOTO")
			GOTO(attributes);
		if (command == "GODTLA")
			GODTLA(attributes);
		if (command == "CIRCLE")
			CIRCLE(attributes);
		if (command == "MSYS")
			MSYS(attributes);
		if (command == "ENDOFPATH")
			END_OF_PATH();
	}

	input.close();
	output.close();
}

/*void APTSource::counter() {
	input.open(inputFileName);
	int temp;
	string line;
	string command;
	int calsub = 0;
	int coolnt = 0;
	int cutcom = 0;
	int cycle = 0;
	int end = 0;
	int fedrat = 0;
	int limit = 0;
	int loadtl = 0;
	int machin = 0;
	int moveto = 0;
	int msys = 0;
	int ofstno = 0;
	int opname = 0;
	int optype = 0;
	int origin = 0;
	int partno = 0;
	int pprint = 0;
	int rapid = 0;
	int rewind = 0;
	int spindl = 0;
	int stop = 0;
	int tlname = 0;
	int toolno = 0;
	int GOTO = 0;
	int move = 0;
	int toler = 0;
	int intol = 0;
	int outtol = 0;
	int cutter = 0;
	int multax = 0;
	int units = 0;
	int tlaxis = 0;
	int fini = 0;
	int contrl = 0;
	int syn = 0;
	int movarc = 0;

	while (getline(input, line)) {
		temp = line.find_first_of('/');
		command = removeSpaces(line.substr(0, temp));

		if (command == "CALSUB")
			calsub++;
		if (command == "COOLNT")
			coolnt++;
		if (command == "CUTCOM")
			cutcom++;
		if (command == "CYCLE")
			cycle++;
		if (command == "END")
			end++;
		if (command == "FEDRAT")
			fedrat++;
		if (command == "LIMIT")
			limit++;
		if (command == "LOADTL")
			loadtl++;
		if (command == "MACHIN")
			machin++;
		if (command == "MOVETO")
			moveto++;
		if (command == "MSYS")
			msys++;
		if (command == "OFSTNO")
			ofstno++;
		if (command == "OPNAME")
			opname++;
		if (command == "OPTYPE")
			optype++;
		if (command == "ORIGIN")
			origin++;
		if (command == "PARTNO")
			partno++;
		if (command == "PPRINT")
			pprint++;
		if (command == "RAPID")
			rapid++;
		if (command == "SPINDL")
			spindl++;
		if (command == "STOP")
			stop++;
		if (command == "TLNAME")
			tlname++;
		if (command == "TOOLNO")
			toolno++;
		if (command == "GOTO")
			GOTO++;
		if (command == "MOVE")
			move++;
		if (command == "TOLER")
			toler++;
		if (command == "INTOL")
			intol++;
		if (command == "OUTTOL")
			outtol++;
		if (command == "CUTTER")
			cutter++;
		if (command == "MULTAX")
			multax++;
		if (command == "UNITS")
			units++;
		if (command == "TLAXIS")
			tlaxis++;
		if (command == "FINI")
			fini++;
		if (command == "CONTRL")
			contrl++;
		if (command == "SYN")
			syn++;
		if (command == "MOVARC")
			movarc++;
	}

	std::cout << "CALSUB: " << calsub << "\n";
	std::cout << "COOLNT: " << coolnt << "\n";
	std::cout << "CUTCOM: " << cutcom << "\n";
	std::cout << "CYCLE: " << cycle << "\n";
	std::cout << "END: " << end << "\n";
	std::cout << "FEDRAT: " << fedrat << "\n";
	std::cout << "LIMIT: " << limit << "\n";
	std::cout << "LOADTL: " << loadtl << "\n";
	std::cout << "MACHIN: " << machin << "\n";
	std::cout << "MOVETO: " << moveto << "\n";
	std::cout << "MSYS: " << msys << "\n";
	std::cout << "OFSTNO: " << ofstno << "\n";
	std::cout << "OPNAME: " << opname << "\n";
	std::cout << "OPTYPE: " << optype << "\n";
	std:: << "ORIGIN: " << origin << "\n";
	cout << "PARTNO: " << partno << "\n";
	cout << "PPRINT: " << pprint << "\n";
	cout << "RAPID: " << rapid << "\n";
	cout << "REWIND: " << rewind << "\n";
	cout << "SPINDL: " << spindl << "\n";
	cout << "STOP: " << stop << "\n";
	cout << "TLNAME: " << tlname << "\n";
	cout << "TOOLNO: " << toolno << "\n";
	cout << "GOTO: " << GOTO << "\n";
	cout << "MOVE: " << move << "\n";
	cout << "TOLER: " << toler << "\n";
	cout << "INTOL: " << intol << "\n";
	cout << "OUTTOL: " << outtol << "\n";
	cout << "CUTTER: " << cutter << "\n";
	cout << "MULTAX: " << multax << "\n";
	cout << "UNITS: " << units << "\n";
	cout << "TLAXIS: " << tlaxis << "\n";
	cout << "FINI: " << fini << "\n";
	cout << "CONTRL: " << contrl << "\n";
	cout << "SYN: " << syn << "\n";
	cout << "MOVARC: " << movarc << "\n";

	input.close(); 
}*/

void APTSource::TOOL_PATH(vector<string> attributes){
	bool check = false;
	int check_n = 0;
	if (attributes.size() == 3) {
		output << "(" << attributes[0] << " , TOOL: " << attributes[2] << ")\n";
		for (int i = 0; i < station.tool_list.size(); i++) {
			if (station.tool_list[i] == attributes[2]) {
				check = true;
				check_n = i + 1;
			}
		}
		if (check) {
			if (check_n != station.tool_n) {
				output << "N" << gcode_n << " " << "T" << check_n << " M6\n";
				station.tool_n = check_n;
				gcode_n++;
			}
		}
		if (!check) {
			station.tool_list.push_back(attributes[2]);
			station.new_tool = true;
			output << "N" << gcode_n << " " << "T" << station.tool_list.size() << " M6\n";
			gcode_n++;
		}
	}
}
void APTSource::TLDATA(vector<string> attributes){
	
	if (station.new_tool) {
		tool temp(attributes);
		station.tool_catalogue.push_back(temp);
		station.new_tool = false;
	}
}
void APTSource::FEDRAT(vector<string> attributes){
	if (attributes.size() == 2) {
		station.unit = attributes[0];
		station.feedrate = stod(attributes[1]);
		if (station.unit == "IPM") {
			output << "N" << gcode_n << " " << "G20 G94 M3\n";
			gcode_n++;
		}
		else if (station.unit == "IPR") {
			output << "N" << gcode_n << " " << "G20 G95 M3\n";
			gcode_n++;
		}
		else if (station.unit == "MMPM") {
			output << "N" << gcode_n << " " << "G21 G94 M3\n";
			gcode_n;
		}
		else if (station.unit == "MMPR") {
			output << "N" << gcode_n << " " << "G21 G95 M3\n";
			gcode_n;
		}
		else
			std::cout << line_n << ": Not A Valid Feedrate Type\n";
	}
	else {
		cout << "FEDRAT: Wrong ammount of arguments: " << line_n << "\n";
	}
}
void APTSource::RAPID(){
	station.rapid = true;
}
void APTSource::CYCLE(vector<string> attributes){}
void APTSource::GOTO(vector<string> attributes){
	string new_line;
	if (attributes.size() > 0) {
		if (station.arc == false) {
			if (attributes.size() == 6) {
				station.current_x = stod(attributes[0]);
				station.current_y = stod(attributes[1]);
				station.current_z = stod(attributes[2]);
				station.current_i = stod(attributes[3]);
				station.current_j = stod(attributes[4]);
				station.current_k = stod(attributes[5]);

				if (station.rapid == true) {
					output << "N" << gcode_n << " " << "G00" << " X" << attributes[0] << " Y" << attributes[1] << " Z" << attributes[2] << " I" << attributes[3] << " J" << attributes[4] << " K" << attributes[5] << "\n";
					station.rapid = false;
					gcode_n++;
				}
				if (station.rapid == false) {
					output << "N" << gcode_n << " " << "G01" << " X" << attributes[0] << " Y" << attributes[1] << " Z" << attributes[2] << " I" << attributes[3] << " J" << attributes[4] << " K" << attributes[5] << " F" << station.feedrate << "\n";
					gcode_n++;
				}
			}
			else if (attributes.size() == 3) {
				station.current_x = stod(attributes[0]);
				station.current_y = stod(attributes[1]);
				station.current_z = stod(attributes[2]);

				if (station.rapid == true) {
					output << "N" << gcode_n << " " << "G00" << " X" << attributes[0] << " Y" << attributes[1] << " Z" << attributes[2] << "\n";
					station.rapid = false;
					gcode_n++;
				}
				if (station.rapid == false) {
					output << "N" << gcode_n << " " << "G01" << " X" << attributes[0] << " Y" << attributes[1] << " Z" << attributes[2] << " F" << station.feedrate << "\n";
					gcode_n++;
				}
			}
			else {
				cout << "GOTO: Non standard ammount of arguments: " << line_n << "\n";
			}
		}
		if (station.arc == true) {
			if (station.arc_i == 0 && station.arc_j == 0 && station.arc_k == 1) {
				station.current_x = stod(attributes[0]);
				station.current_y = stod(attributes[1]);
				station.current_z = stod(attributes[2]);
				output << "N" << gcode_n << " " << "G02" << " X" << attributes[0] << " Y" << attributes[1] << " Z" << attributes[2] << " R" << station.arc_r << "\n";
				gcode_n++;
			}
			if (station.arc_i == 0 && station.arc_j == 0 && station.arc_k == -1) {
				station.current_x = stod(attributes[0]);
				station.current_y = stod(attributes[1]);
				station.current_z = stod(attributes[2]);
				output << "N" << gcode_n << " " << "GO3" << " X" << attributes[0] << " Y" << attributes[1] << " Z" << attributes[2] << " R" << station.arc_r << "\n";
				gcode_n++;
			}
			station.arc = false;
		}
	}
	else {
		cout << "GOTO: no arguments found: " << line_n << "\n";
	}

}
void APTSource::GODTLA(vector<string> attributes){
	if (attributes.size() == 3) {
		double move_x = station.current_x + stod(attributes[0]);
		double move_y = station.current_x + stod(attributes[1]);
		double move_z = station.current_x + stod(attributes[2]);
		output << "N" << gcode_n << " " << "G01" << " X" << move_x << " Y" << move_y << " Z" << move_z << "\n";
		gcode_n++;
		station.current_x = move_x;
		station.current_y = move_y;
		station.current_z = move_z;
	}
	else {
		cout << "GODTLA: Not Enough Arguments";
	}
}
void APTSource::CIRCLE(vector<string> attributes){
	if (attributes.size() == 11) {
		station.arc = true;
		station.arc_x = stod(attributes[0]);
		station.arc_y = stod(attributes[1]);
		station.arc_z = stod(attributes[2]);
		station.arc_i = stod(attributes[3]);
		station.arc_j = stod(attributes[4]);
		station.arc_k = stod(attributes[5]);
		station.arc_r = stod(attributes[6]);
		station.arc_t = stod(attributes[7]);
		station.arc_f = stod(attributes[8]);
		station.arc_d = stod(attributes[9]);
		station.arc_e = stod(attributes[10]);
	}
	else {
		cout << "CIRCLE: Not Enough Arguments: " <<  line_n << "\n";
	}
}
void APTSource::MSYS(vector<string> attributes){
	if (attributes.size() == 9) {
		if (stod(attributes[0]) == 0 && stod(attributes[1]) == 0 && stod(attributes[2]) == 0 && stod(attributes[3]) == 1 && stod(attributes[4]) == 0 &&	stod(attributes[5]) == 0 && stod(attributes[6]) == 0 && stod(attributes[7]) == 1 && stod(attributes[8]) == 0) {
			output << "N" << gcode_n << " " << "G54\n";
			gcode_n++;
		}
	}
}
void APTSource::END_OF_PATH(){
	output << "N" << gcode_n << " " << "M5\n";
	gcode_n++;
}