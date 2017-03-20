#include <string>
#include "Errors.h"

std::string Row_error::what() const  {
	return "Error: " + s;
}
