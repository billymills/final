#include <iostream>
#include <string>

#include "Entry.h"

Entry::Entry(string k){
	key = k;
	//value = v;
	int count = 1;
}

int Entry::getCount(){
	return count;
}

void Entry::setCount(int c){
	count = c;
}
