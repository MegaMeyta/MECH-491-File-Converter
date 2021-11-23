#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "APT Source.h"

using namespace std;
using namespace apt;

int main() {

	APTSource basic("start.txt");
	basic.convert();


	return 0;
}
