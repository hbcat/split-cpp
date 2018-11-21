#include <string>
#include <iostream>
#include <vector>
#include "split.h"

using namespace std;

Csplit::Csplit()
{
	reset();
}

void Csplit::reset()
{
	spl.resize(0);
}

const string& Csplit::join(const vector<string>& words, const string& _sep)
{
         sen = "";
         string sep = _sep;
         for(auto & wd : words) {
              sen += wd + sep; 
         }

         return sen;
}


vector<string>& Csplit::split(const string& _str, const string& _sep) 
{
	if(_str.empty()) {
		return spl;
	}

	reset();

	string::size_type found = 0;
	string::size_type sub_begin = 0;
	string::size_type sub_end = 0;
	string::size_type sub_len = 0;
	string sub_str = "";
	found = _str.find(_sep);
	if( found != string::npos) {
		sub_end = found;
		sub_len = sub_end - sub_begin;
		sub_str = _str.substr(sub_begin, sub_len);
		if( !sub_str.empty() ){
			//cout << sub_str << endl;
			spl.push_back(sub_str);
		}

		while( found != string::npos ) {
			sub_begin = sub_end + 1;
			//cout << "sub_begin: " << sub_begin << endl;
			//cout << _str.substr(sub_begin) << endl;
			found = _str.find(_sep, sub_begin);	
			sub_end = found;
			//cout << "sub_end: " << sub_end << endl;
			sub_len = sub_end - sub_begin;
			sub_str = _str.substr(sub_begin, sub_len);
			if( !sub_str.empty() ){
				spl.push_back(sub_str);
			}
		}
	}else{
		spl.push_back(_str);
	}

	 
	
	return spl;
}
