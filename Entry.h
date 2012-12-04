#ifndef __ENTRY_H__
#define __ENTRY_H__

#include <string>

using std::string;

class Entry{
	private:
		int key;
		string value;
		int count;
	public:
		Entry(int k, string v, int c);
		int getCount();
		void setCount(int c);
};

#endif
