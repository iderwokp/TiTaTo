#ifndef ERRORS_H
#define ERRORS_H

#include <string>

class Row_error { 	 //Exception handling
	std::string s;
	public:
		Row_error(std::string str):s{str} {}
		std::string what() const;  
};

#endif
