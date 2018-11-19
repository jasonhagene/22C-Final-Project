#include <string>
#include "Location.h"
#pragma once

class Contact {
private:
	Location location;
	std::string name;
	std::string address;
	int contactNum;
public:
	std::string getName() { return name; }
	std::string getAddress() { return address; }
	int getContactNum() { return contactNum; }
	Location getLocation(){ return location; }
};