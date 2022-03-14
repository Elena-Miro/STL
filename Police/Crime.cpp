#include "Crime.h"

std::ostream& operator<<(std::ostream& os, const Crime& obj)
{
	os << crimes.at(obj.get_id()) << ", " << obj.get_place();
	return os;
}

std::ofstream& operator<<(std::ofstream& ofs, const Crime& obj)
{
	ofs << obj.get_id() << " " << obj.get_place();
	return ofs;
}