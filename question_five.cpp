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

int main (){

	ifstream tweets;
	tweets.open ("tweets");
	if (!tweets.is_open()){
		cout << "could not open file!" << endl;
	}
	else {
		cout << "the file is open" << endl;
	}

	map <string, int> santasList;
/*
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
			
		while (getline(file, x)){

				if (santasList.count(x) == 0){
					santasList.insert(pair<string, int>(x, 1));
				}
				else {
					santasList.insert(pair<string, int>(x,++santasList[x]));
				}
			}
		}
	}

	//print out the nice people first (those above threshold)
	cout << "The Nice List: " << endl;
	//int threshold = atoi(argv[2]);
	map <string, int>::iterator it;
	for (it = santasList.begin(); it != santasList.end(); ++it){
		if (it->second >= atoi(argv[2])){
			cout << it->first << endl;
		}
	}

	//print out the naughty people next (below threshhold)
	cout << "The Naughty List: " << endl;
	for (it = santasList.begin(); it != santasList.end(); ++it){
		if (it->second < atoi(argv[2])){
			cout << it->first << endl;
		}
	}
*/
	return 0;
}
