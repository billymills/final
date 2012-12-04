#include <iostream>
#include <string>

#include "Entry.h"

Entry::Entry(int k, string v, int c){
	key = k;
	value = v;
	count = c;
}

int Entry::getCount(){
	return count;
}
