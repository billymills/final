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
	multimap <int, string> flip;
	ifstream tweets;
	ofstream rankedList;
	ofstream lexical;
	
	int wordCount = 0;

	//open data file
	tweets.open ("tweets");
	if (!tweets.is_open()){
		cout << "could not open file!" << endl;
	}
	else {
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

				}  //end else

			} //end inner while

		}  //end while

	}  //end else
	
	//insert list into another structure for ranking

	map <string, int>::iterator it;
	for (it = tweetMap.begin(); it != tweetMap.end(); ++it){
		flip.insert(pair<int, string>(it->second, it->first));
	}
	
	//cout << flip.size() << endl;
	
	//output ranked list to file
	multimap <int, string>::reverse_iterator rit;
	rankedList.open ("ranked_list");
		for (rit = flip.rbegin(); rit != flip.rend(); ++rit){
			rankedList << rit->second << "   " << rit->first << endl;
		}

	rankedList.close();

	//output lexical analysis to file
	lexical.open ("lexical_analysis");
		lexical << "Total Words: " << wordCount << endl;
		lexical << "Unique Words: " << tweetMap.size() << endl;
		lexical << "Lexical Diversity: " << (double) wordCount/tweetMap.size() << endl;
	lexical.close();

	cout << "lexical_analysis and ranked_list files have been created" << endl;

	return 0;
}
