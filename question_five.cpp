#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <ctype.h>


using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::getline;
using std::map;
using std::pair;
using std::istringstream;


int main (){
	map <string, int> tweetMap;
	int wordCount = 0;

	ifstream tweets;
	tweets.open ("nice.dat");
	if (!tweets.is_open()){
		cout << "could not open file!" << endl;
	}
	else {
		cout << "the file is open" << endl;
		string x;

		while (getline(tweets, x)){
			
			istringstream myString(x);
			while (myString){
				string word;
				myString >> word;
				if (word != ""){
					++wordCount;
					//convert words to lower case
					for(int i = 0; word[i] != '\0'; i++){
						word[i] = tolower(word[i]);
					}
					if (tweetMap.count(word) == 0){
						tweetMap.insert(pair<string, int>(word, 1));
					}
					else {
						tweetMap.insert(pair<string, int>(word,++tweetMap[word]));
					}
				}
			}
		}
				
		
		
	}
	cout << wordCount << endl;
	cout << "uniques: " << tweetMap.size() << endl;

/*

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
	ofstream output;
	output.open ("output.txt");
	output << "hello" << endl;
	output.close();
	return 0;
}
