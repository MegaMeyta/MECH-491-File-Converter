#include "APT Source.h"
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <iostream>

using namespace apt;

workstation::workstation() {
	rapid = false;
	for (int i = 0; i < 3; i++) {
		for (int a = 0; a < 3; a++) {
			absolute[i][a] = 0;
		}
	}
	feedrate = 0;
	unit = "metric";
	tool_diameter = 0;
	tool_upper_radius = 0;
	tool_lower_radius = 0;
	tool_length = 0;
	tool_taper_angle = 0;
	tool_tip_angle = 0;
	tool_x_center_r1 = 0;
	tool_y_center_r1 = 0;
	tool_x_center_r2 = 0;
	tool_y_center_r2 = 0;
}

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
		if (command == "CSLF")
			CSLF(attributes);
		if (command == "ENDOFPATH")
			END_OF_PATH();
	}

	input.close();
	output.close();
}

void APTSource::counter() {
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

	cout << "CALSUB: " << calsub << "\n";
	cout << "COOLNT: " << coolnt << "\n";
	cout << "CUTCOM: " << cutcom << "\n";
	cout << "CYCLE: " << cycle << "\n";
	cout << "END: " << end << "\n";
	cout << "FEDRAT: " << fedrat << "\n";
	cout << "LIMIT: " << limit << "\n";
	cout << "LOADTL: " << loadtl << "\n";
	cout << "MACHIN: " << machin << "\n";
	cout << "MOVETO: " << moveto << "\n";
	cout << "MSYS: " << msys << "\n";
	cout << "OFSTNO: " << ofstno << "\n";
	cout << "OPNAME: " << opname << "\n";
	cout << "OPTYPE: " << optype << "\n";
	cout << "ORIGIN: " << origin << "\n";
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
}

/*void APTSource::CALSUB(vector<string> attributes) {
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

}*/

void APTSource::TOOL_PATH(vector<string> attributes){}
void APTSource::TLDATA(vector<string> attributes){}
void APTSource::FEDRAT(vector<string> attributes){
	if (attributes.size() == 2) {
		station.unit = attributes[0];
		station.feedrate = stod(attributes[1]);
	}
	else {
		cout << "FEDRAT: Wrong ammount of arguments \n";
	}
}
void APTSource::RAPID(){
	station.rapid = true;
}
void APTSource::CYCLE(vector<string> attributes){}
void APTSource::GOTO(vector<string> attributes){
	string new_line;
	if (attributes.size() > 0) {
		if (attributes.size() == 6) {
			if (station.rapid = true) {
				output << "G00" << " X" << attributes[0] << " Y" << attributes[1] << " Z" << attributes[2] << " I" << attributes[3] << " J" << attributes[4] << " K" << attributes[5] << "\n";
				station.rapid = false;
			}
			if (station.rapid = false) {
				output << "G01" << " X" << attributes[0] << " Y" << attributes[1] << " Z" << attributes[2] << " I" << attributes[3] << " J" << attributes[4] << " K" << attributes[5] << " F" << station.feedrate <<"\n";
			}
		}
		if (attributes.size() == 3) {
			if (station.rapid = true) {
				output << "G00" << " X" << attributes[0] << " Y" << attributes[1] << " Z" << attributes[2] << "\n";
				station.rapid = false;
			}
			if (station.rapid = false) {
				output << "G01" << " X" << attributes[0] << " Y" << attributes[1] << " Z" << attributes[2] << " F" << station.feedrate << "\n";
			}
		}
		else {
			cout << "GOTO: Non standard ammount of arguments \n";
		}
	}
	else {
		cout << "GOTO: no arguments found \n";
	}

}
void APTSource::GODTLA(vector<string> attributes){}
void APTSource::CIRCLE(vector<string> attributes){}
void APTSource::MSYS(vector<string> attributes){}
void APTSource::CSLF(vector<string> attributes){}
void APTSource::END_OF_PATH(){}