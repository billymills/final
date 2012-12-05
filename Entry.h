#ifndef __ENTRY_H__
#define __ENTRY_H__

#include <string>

using std::string;

class Entry{
	private:
		string key;
		//string value;
		int count;
	public:
		Entry(string);
		int getCount();
		void setCount(int c);
};

#endif
