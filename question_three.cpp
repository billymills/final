#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>


using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::getline;

int main (int argc, char** argv){
	
	//three arguments are needed executable, filename, threshold
	if (argc != 3){	
		cout << "Usage: list [filename] [threshold]" << endl;
	}
	else {
		cout << "filename: " << argv[1] << endl;  //name of file
		cout << "threshold: " << argv[2] << endl; //threshold

		ifstream file (argv[1]);
		if (!file.is_open())
			cout << "could not open file" << endl;
		else{
			cout << "the file is open" << endl;
			string x;
			while (getline(file, x))
				cout << x << endl;
		}
	}	
	return 0;

}
