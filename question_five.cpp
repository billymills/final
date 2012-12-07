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
using std::multimap;
using std::pair;
using std::istringstream;


int main (){
	map <string, int> tweetMap;
	int wordCount = 0;
	ofstream rankedList;

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
	

	//insert list into another structure for ranking
	multimap <int, string> flip;

	map <string, int>::iterator it;
	for (it = tweetMap.begin(); it != tweetMap.end(); ++it){
		flip.insert(pair<int, string>(it->second, it->first));
	}
	cout << flip.size() << endl;
	//output ranked list to file
	multimap <int, string>::reverse_iterator rit;
	rankedList.open ("rankedList");
	for (rit = flip.rbegin(); rit != flip.rend(); ++rit){
		rankedList << rit->second << "   " << rit->first << endl;
	}

	rankedList.close();

	return 0;
}
