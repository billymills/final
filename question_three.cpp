#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <map>

#include "Entry.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::getline;
using std::map;
using std::pair;

int main (int argc, char** argv){
	map <string, int> santasList;
	//three arguments are needed executable, filename, threshold
	if (argc != 3){	
		cout << "Usage: list [filename] [threshold]" << endl;
	}
	else {
		cout << "filename: " << argv[1] << endl;  //name of file
		cout << "threshold: " << argv[2] << endl; //threshold

		ifstream file (argv[1]);
		if (!file.is_open()){
			cout << "could not open file" << endl;
		}
		else{
			cout << "the file is open" << endl;
			string x;
			//int i = 0;
			while (getline(file, x)){
				cout << x << endl;
				//insert entry into map
				//santasList.insert(pair<string, Entry>(x, Entry(x)));

				if (santasList.count(x) == 0){
					santasList.insert(pair<string, int>(x, 1));
				}
				else {
					santasList.insert(pair<string, int>(x,++santasList[x]));
				}
				//++i;
			}
		}
	}
	if (santasList.count("merry") > 0){
		cout << "not empty" << endl;
	}
	//cout << santasList.size() << endl;	
	//cout << santasList.count("merry") << endl;
	cout << santasList["merry"] << endl;
	return 0;

}
