#include "APT Source.h"
#include <string>
#include <fstream>
#include <vector>
#include <map>


void apt::CALSUB(FILE& output, vector<string> attributes) {
	if (attributes[3] == "CLDATA") {

	}

	if (attributes[3] == "SYSTEM") {

	}

	if (attributes[3] == "INCLUD") {

	}

}

void apt::COOLNT(FILE& output, vector<string> attributes) {

}

void apt::CUTCOM(FILE& output, vector<string> attributes) {
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

void apt::CYCLE(FILE& output, vector<string> attributes);

void apt::END(FILE& output, vector<string> attributes);

void apt::FEDRAT(FILE& output, vector<string> attributes);

void apt::LIMIT(FILE& output, vector<string> attributes);

void apt::LOADTL(FILE& output, vector<string> attributes);

void apt::MACHIN(FILE& output, vector<string> attributes);

void apt::MOVETO(FILE& output, vector<string> attributes);

void apt::MSYS(FILE& output, vector<string> attributes);

void apt::OFSTNO(FILE& output, vector<string> attributes);

void apt::OPNAME(FILE& output, vector<string> attributes);

void apt::OPTYPE(FILE& output, vector<string> attributes);

void apt::ORIGIN(FILE& output, vector<string> attributes);

void apt::PARTNO(FILE& output, vector<string> attributes);

void apt::PPRINT(FILE& output, vector<string> attributes);

void apt::RAPID(FILE& output, vector<string> attributes);

void apt::REWIND(FILE& output, vector<string> attributes);

void apt::SPINDL(FILE& output, vector<string> attributes);

void apt::STOP(FILE& output, vector<string> attributes);

void apt::TLNAME(FILE& output, vector<string> attributes);

void apt::TOOLNO(FILE& output, vector<string> attributes);

void apt::GOTO(FILE& output, vector<string> attributes);

void apt::MOVE(FILE& output, vector<string> attributes);

void apt::TOLER(FILE& output, vector<string> attributes);

void apt::INTOL(FILE& output, vector<string> attributes);

void apt::OUTTOL(FILE& output, vector<string> attributes);

void apt::CUTTER(FILE& output, vector<string> attributes);

void apt::MULTAX(FILE& output, vector<string> attributes);

void apt::UNITS(FILE& output, vector<string> attributes);

void apt::TLAXIS(FILE& output, vector<string> attributes);

void apt::FINI(FILE& output, vector<string> attributes);

void apt::CONTRL(FILE& output, vector<string> attributes);

void apt::SYN(FILE& output, vector<string> attributes);

void apt::MOVARC(FILE& output, vector<string> attributes);