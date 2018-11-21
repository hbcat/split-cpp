#ifndef _SPLIT_H_
#define _SPLIT_H_

#include <vector>
#include <string>

using namespace std;

class Csplit {
public:
	Csplit();
	vector<string>& split(const string& _str, const string& _sep);	
        const string& join(const vector<string>& words, const string& _sep);
	void reset();
private:	
	string separator;
        string sen;
	vector<string> spl; 	
};

#endif
