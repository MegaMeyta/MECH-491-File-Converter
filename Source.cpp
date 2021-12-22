#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "APT Source.h"

using namespace std;
using namespace apt;

int main() {
	string filename;
	cout << "MECH 491 NX CSLF to G-Code Post Processor \n By Joshua Metz and Rohit Shabu \n\n Type in the name of the file you wish to post process (with extension): ";
	cin >> filename;
	APTSource basic(filename);
	basic.convert();


	return 0;
}
