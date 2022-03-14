#include "Crime.h"

std::ostream& operator<<(std::ostream& os, const Crime& obj)
{
	os << crimes.at(obj.get_id()) << ", " << obj.get_place();
	return os;
}