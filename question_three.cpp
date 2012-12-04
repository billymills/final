#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

int main (int argc, char** argv){
	
	//three arguments are needed executable, filename, threshold
	if (argc != 3){	
		cout << "Usage: list [filename] [threshold]" << endl;
	}
	else {
		cout << "filename: " << argv[1] << endl;  //name of file
		cout << "threshold: " << argv[2] << endl; //threshold
	}	
	return 0;

}
